#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "ast.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/Mangling.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/StandardInstrumentations.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Scalar/Reassociate.h"
#include "llvm/Transforms/Scalar/SimplifyCFG.h"

#define KEYWORD_DEFINE "def"
#define KEYWORD_EXTERN "extern"
#define KEYWORD_IF "if"
#define KEYWORD_THEN "then"
#define KEYWORD_ELSE "else"
#define KEYWORD_FOR "for"
#define KEYWORD_IN "in"

enum Token {
  TOKEN_EOF,
  TOKEN_DEF,
  TOKEN_EXTERN,
  TOKEN_IDENTIFIER,
  TOKEN_NUMBER,
  TOKEN_IF,
  TOKEN_THEN,
  TOKEN_ELSE,
  TOKEN_FOR,
  TOKEN_IN,
  TOKEN_CHAR,
};

class ToyLanguageJIT {
 public:
  ToyLanguageJIT(std::unique_ptr<llvm::orc::ExecutionSession> ES,
                 llvm::orc::JITTargetMachineBuilder JTMB, llvm::DataLayout DL)
      : ES_(std::move(ES)),
        DL_(std::move(DL)),
        mangle_(*this->ES_, this->DL_),
        object_layer_(
            *this->ES_,
            []() { return std::make_unique<llvm::SectionMemoryManager>(); }),
        compile_layer_(
            *this->ES_, object_layer_,
            std::make_unique<llvm::orc::ConcurrentIRCompiler>(std::move(JTMB))),
        jit_dylib_(this->ES_->createBareJITDylib("<main>")) {
    jit_dylib_.addGenerator(
        cantFail(llvm::orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(
            DL.getGlobalPrefix())));
    if (JTMB.getTargetTriple().isOSBinFormatCOFF()) {
      object_layer_.setOverrideObjectFlagsWithResponsibilityFlags(true);
      object_layer_.setAutoClaimResponsibilityForObjectSymbols(true);
    }
  }

  ~ToyLanguageJIT() {
    if (auto Err = ES_->endSession()) ES_->reportError(std::move(Err));
  }

  static llvm::Expected<std::unique_ptr<ToyLanguageJIT>> Create() {
    auto EPC = llvm::orc::SelfExecutorProcessControl::Create();
    if (!EPC) return EPC.takeError();

    auto ES = std::make_unique<llvm::orc::ExecutionSession>(std::move(*EPC));

    llvm::orc::JITTargetMachineBuilder JTMB(
        ES->getExecutorProcessControl().getTargetTriple());

    auto DL = JTMB.getDefaultDataLayoutForTarget();
    if (!DL) return DL.takeError();

    return std::make_unique<ToyLanguageJIT>(std::move(ES), std::move(JTMB),
                                            std::move(*DL));
  }

  const llvm::DataLayout& getDataLayout() const { return DL_; }

  llvm::orc::JITDylib& getMainJITDylib() { return jit_dylib_; }

  llvm::Error addModule(llvm::orc::ThreadSafeModule TSM,
                        llvm::orc::ResourceTrackerSP RT = nullptr) {
    if (!RT) RT = jit_dylib_.getDefaultResourceTracker();
    return compile_layer_.add(RT, std::move(TSM));
  }

  llvm::Expected<llvm::orc::ExecutorSymbolDef> lookup(llvm::StringRef Name) {
    return ES_->lookup({&jit_dylib_}, mangle_(Name.str()));
  }

 private:
  std::unique_ptr<llvm::orc::ExecutionSession> ES_;

  llvm::DataLayout DL_;
  llvm::orc::MangleAndInterner mangle_;
  llvm::orc::RTDyldObjectLinkingLayer object_layer_;
  llvm::orc::IRCompileLayer compile_layer_;
  llvm::orc::JITDylib& jit_dylib_;
};

void InitializeModuleAndManagers();

static std::unordered_map<char, int> precedence;
static llvm::ExitOnError ExitOnErr;
static std::unique_ptr<ToyLanguageJIT> jit;
static std::unique_ptr<llvm::LLVMContext> llvm_context;
static std::unique_ptr<llvm::Module> module;
static std::unique_ptr<llvm::IRBuilder<>> ir_builder;
static std::unordered_map<std::string, llvm::Value*> named_values;
static std::unique_ptr<llvm::FunctionPassManager> FPM;
static std::unique_ptr<llvm::LoopAnalysisManager> LAM;
static std::unique_ptr<llvm::FunctionAnalysisManager> FAM;
static std::unique_ptr<llvm::CGSCCAnalysisManager> CGAM;
static std::unique_ptr<llvm::ModuleAnalysisManager> MAM;
static std::unique_ptr<llvm::PassInstrumentationCallbacks> PIC;
static std::unique_ptr<llvm::StandardInstrumentations> SI;
static std::unordered_map<std::string, std::unique_ptr<PrototypeAST>>
    function_protos;

llvm::Value* NumberExprAST::codegen() {
  return llvm::ConstantFP::get(*llvm_context, llvm::APFloat(val_));
}

llvm::Value* VariableExprAST::codegen() {
  llvm::Value* val = named_values[name_];
  if (!val) {
    std::cerr << "Unknown variable name" << std::endl;
    return nullptr;
  }
  return val;
}

llvm::Value* BinaryExprAST::codegen() {
  llvm::Value* L = LHS_->codegen();
  llvm::Value* R = RHS_->codegen();
  if (!L || !R) {
    return nullptr;
  }
  switch (op_) {
    case '+':
      return ir_builder->CreateFAdd(L, R, "add");
    case '-':
      return ir_builder->CreateFSub(L, R, "sub");
    case '*':
      return ir_builder->CreateFMul(L, R, "mul");
    case '/':
      return ir_builder->CreateFDiv(L, R, "div");
    case '<':
      L = ir_builder->CreateFCmpULT(L, R, "less_than");
      return ir_builder->CreateUIToFP(L, llvm::Type::getDoubleTy(*llvm_context),
                                      "less_then_bool");
    case '>':
      L = ir_builder->CreateFCmpUGT(L, R, "greater_than");
      return ir_builder->CreateUIToFP(L, llvm::Type::getDoubleTy(*llvm_context),
                                      "greater_then_bool");
    default:
      std::cerr << "invalid binary operator" << std::endl;
      return nullptr;
  }
}

llvm::Function* get_function(const std::string& name) {
  auto* f = module->getFunction(name);
  if (f) {
    return f;
  }

  if (function_protos.count(name)) {
    return function_protos[name]->codegen();
  }
  return nullptr;
}

llvm::Value* CallExprAST::codegen() {
  llvm::Function* callee = get_function(callee_);
  if (!callee) {
    std::cerr << "Unknown function referenced" << std::endl;
    return nullptr;
  }

  if (callee->arg_size() != args_.size()) {
    std::cerr << "Incorrect number of arguments" << std::endl;
    return nullptr;
  }

  std::vector<llvm::Value*> arg_variables;
  for (int i = 0; i < (int)args_.size(); ++i) {
    arg_variables.push_back(args_[i]->codegen());
    if (!arg_variables.back()) {
      return nullptr;
    }
  }
  return ir_builder->CreateCall(callee, arg_variables, "call");
}

llvm::Value* IfExprAST::codegen() {
  llvm::Value* cond_value = cond_->codegen();
  if (!cond_value) {
    return nullptr;
  }

  // Convert condition to a bool by comparing non-equal to 0.0.
  cond_value = ir_builder->CreateFCmpONE(
      cond_value, llvm::ConstantFP::get(*llvm_context, llvm::APFloat(0.0)),
      "ifcond");

  llvm::Function* func = ir_builder->GetInsertBlock()->getParent();

  // Create blocks for the then and else cases.  Insert the 'then' block at the
  // end of the function.
  llvm::BasicBlock* then_block =
      llvm::BasicBlock::Create(*llvm_context, "then", func);
  llvm::BasicBlock* else_block =
      llvm::BasicBlock::Create(*llvm_context, "else");
  llvm::BasicBlock* merge_block =
      llvm::BasicBlock::Create(*llvm_context, "ifcont");

  ir_builder->CreateCondBr(cond_value, then_block, else_block);

  // Emit then value.
  ir_builder->SetInsertPoint(then_block);

  llvm::Value* then_value = then_->codegen();
  if (!then_value) {
    return nullptr;
  }

  ir_builder->CreateBr(merge_block);
  // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
  then_block = ir_builder->GetInsertBlock();

  // Emit else block.
  func->insert(func->end(), else_block);
  ir_builder->SetInsertPoint(else_block);

  llvm::Value* else_value = else_->codegen();
  if (!else_value) return nullptr;

  ir_builder->CreateBr(merge_block);
  // Codegen of 'Else' can change the current block, update ElseBB for the PHI.
  else_block = ir_builder->GetInsertBlock();

  // Emit merge block.
  func->insert(func->end(), merge_block);
  ir_builder->SetInsertPoint(merge_block);
  llvm::PHINode* phi_node =
      ir_builder->CreatePHI(llvm::Type::getDoubleTy(*llvm_context), 2, "if");

  phi_node->addIncoming(then_value, then_block);
  phi_node->addIncoming(else_value, else_block);
  return phi_node;
}

llvm::Value* ForExprAST::codegen() {
  // Emit the start code first, without 'variable' in scope.
  llvm::Value* start_val = start_->codegen();
  if (!start_val) return nullptr;

  // Make the new basic block for the loop header, inserting after current
  // block.
  llvm::Function* func = ir_builder->GetInsertBlock()->getParent();
  llvm::BasicBlock* preheader_block = ir_builder->GetInsertBlock();
  llvm::BasicBlock* loop_block =
      llvm::BasicBlock::Create(*llvm_context, "loop", func);

  // Insert an explicit fall through from the current block to the LoopBB.
  ir_builder->CreateBr(loop_block);

  // Start insertion in LoopBB.
  ir_builder->SetInsertPoint(loop_block);

  // Start the PHI node with an entry for Start.
  llvm::PHINode* phi_node = ir_builder->CreatePHI(
      llvm::Type::getDoubleTy(*llvm_context), 2, varname_);
  phi_node->addIncoming(start_val, preheader_block);

  // Within the loop, the variable is defined equal to the PHI node.  If it
  // shadows an existing variable, we have to restore it, so save it now.
  llvm::Value* old_val = named_values[varname_];
  named_values[varname_] = phi_node;

  // Emit the body of the loop.  This, like any other expr, can change the
  // current BB.  Note that we ignore the value computed by the body, but don't
  // allow an error.
  if (!body_->codegen()) return nullptr;

  // Emit the step value.
  llvm::Value* step_val = nullptr;
  if (step_) {
    step_val = step_->codegen();
    if (!step_val) return nullptr;
  } else {
    // If not specified, use 1.0.
    step_val = llvm::ConstantFP::get(*llvm_context, llvm::APFloat(1.0));
  }

  llvm::Value* next_var = ir_builder->CreateFAdd(phi_node, step_val, "nextvar");

  // Compute the end condition.
  llvm::Value* end_cond = end_->codegen();
  if (!end_cond) return nullptr;

  // Convert condition to a bool by comparing non-equal to 0.0.
  end_cond = ir_builder->CreateFCmpONE(
      end_cond, llvm::ConstantFP::get(*llvm_context, llvm::APFloat(0.0)),
      "loopcond");

  // Create the "after loop" block and insert it.
  llvm::BasicBlock* loop_end_block = ir_builder->GetInsertBlock();
  llvm::BasicBlock* after_block =
      llvm::BasicBlock::Create(*llvm_context, "afterloop", func);

  // Insert the conditional branch into the end of LoopEndBB.
  ir_builder->CreateCondBr(end_cond, loop_block, after_block);

  // Any new code will be inserted in AfterBB.
  ir_builder->SetInsertPoint(after_block);

  // Add a new entry to the PHI node for the backedge.
  phi_node->addIncoming(next_var, loop_end_block);

  // Restore the unshadowed variable.
  if (old_val) {
    named_values[varname_] = old_val;
  } else {
    named_values.erase(varname_);
  }

  // for expr always returns 0.0.
  return llvm::Constant::getNullValue(llvm::Type::getDoubleTy(*llvm_context));
}

llvm::Function* PrototypeAST::codegen() {
  // Make the function type:  double(double,double) etc.
  std::vector<llvm::Type*> Doubles(args_.size(),
                                   llvm::Type::getDoubleTy(*llvm_context));
  llvm::FunctionType* func_type = llvm::FunctionType::get(
      llvm::Type::getDoubleTy(*llvm_context), Doubles, false);

  llvm::Function* func = llvm::Function::Create(
      func_type, llvm::Function::ExternalLinkage, name_, module.get());

  // Set names for all arguments.
  unsigned k = 0;
  for (auto& arg : func->args()) arg.setName(args_[k++]);

  return func;
}

llvm::Function* FunctionAST::codegen() {
  // Transfer ownership of the prototype to the FunctionProtos map, but keep a
  // reference to it for use below.
  auto& P = *proto_;
  function_protos[proto_->get_name()] = std::move(proto_);
  llvm::Function* func = get_function(P.get_name());
  if (!func) {
    return nullptr;
  }

  // Create a new basic block to start insertion into.
  llvm::BasicBlock* block =
      llvm::BasicBlock::Create(*llvm_context, "entry", func);
  ir_builder->SetInsertPoint(block);

  // Record the function arguments in the NamedValues map.
  named_values.clear();
  for (auto& Arg : func->args()) {
    named_values[std::string(Arg.getName())] = &Arg;
  }

  if (llvm::Value* RetVal = body_->codegen()) {
    // Finish off the function.
    ir_builder->CreateRet(RetVal);

    // Validate the generated code, checking for consistency.
    llvm::verifyFunction(*func);

    // Run the optimizer on the function.
    FPM->run(*func, *FAM);
    return func;
  }

  // Error reading body, remove function.
  func->eraseFromParent();
  return nullptr;
}

class Parser {
 public:
  Parser(const std::string& code) : code_(code), index_(0), last_char_(' ') {}

  char get_char() {
    if (index_ < code_.size()) {
      return code_[index_++];
    }
    return EOF;
  }

  Token get_token() {
    while (isspace(last_char_)) {
      last_char_ = get_char();
    }

    if (isalpha(last_char_)) {
      identifier_.clear();
      while (isalnum(last_char_)) {
        identifier_.push_back(last_char_);
        last_char_ = get_char();
      }

      if (identifier_ == KEYWORD_DEFINE) {
        return TOKEN_DEF;
      } else if (identifier_ == KEYWORD_EXTERN) {
        return TOKEN_EXTERN;
      } else if (identifier_ == KEYWORD_IF) {
        return TOKEN_IF;
      } else if (identifier_ == KEYWORD_THEN) {
        return TOKEN_THEN;
      } else if (identifier_ == KEYWORD_ELSE) {
        return TOKEN_ELSE;
      } else if (identifier_ == KEYWORD_FOR) {
        return TOKEN_FOR;
      } else if (identifier_ == KEYWORD_IN) {
        return TOKEN_IN;
      }
      return TOKEN_IDENTIFIER;
    }

    if (isdigit(last_char_) || last_char_ == '.') {
      std::string number;
      while (isdigit(last_char_) || last_char_ == '.') {
        number.push_back(last_char_);
        last_char_ = get_char();
      }
      numeric_value_ = stod(number);
      return TOKEN_NUMBER;
    }

    if (last_char_ == '#') {
      do {
        last_char_ = get_char();
      } while (last_char_ != EOF && last_char_ != '\n' && last_char_ != '\r');

      if (last_char_ != EOF) {
        return get_token();
      }
    }

    if (last_char_ == EOF) {
      return TOKEN_EOF;
    }

    current_char_ = last_char_;
    last_char_ = get_char();
    return TOKEN_CHAR;
  }

  Token NextToken() { 
    current_char_ = '\0';
    return current_ = get_token();
  }

  void Parse() {
    NextToken();
    while (true) {
      if (current_ == TOKEN_EOF) {
        return;
      } else if (current_ == TOKEN_CHAR && current_char_ == ';') {
        // ignore top-level semicolons.
        NextToken();
      } else if (current_ == TOKEN_DEF) {
        HandleDefinition();
      } else if (current_ == TOKEN_EXTERN) {
        HandleExtern();
      } else {
        HandleTopLevelExpression();
      }
    }
  }

 private:
  std::unique_ptr<PrototypeAST> ParsePrototype() {
    if (current_ != TOKEN_IDENTIFIER) {
      std::cerr << "Expected function name in prototype." << std::endl;
      return nullptr;
    }

    std::string name = identifier_;
    NextToken();
    if (current_ != TOKEN_CHAR || current_char_ != '(') {
      std::cerr << "Expected ( in prototype" << std::endl;
      return nullptr;
    }

    std::vector<std::string> args;
    while (NextToken() == TOKEN_IDENTIFIER) {
      args.push_back(identifier_);
    }
    if (current_ != TOKEN_CHAR || current_char_ != ')') {
      std::cerr << "Expected ) in prototype" << std::endl;
      return nullptr;
    }

    NextToken();
    return std::make_unique<PrototypeAST>(name, std::move(args));
  }

  std::unique_ptr<ExprAST> ParseIdentifierExpr() {
    std::string name = identifier_;
    NextToken();
    // std::cout << "ParseIdentifier: " << " token=" << current_ << ", identifier=" << identifier_ << ", current char=" << current_char_ << std::endl;
    if (current_ != TOKEN_CHAR || current_char_ != '(') {
      return std::make_unique<VariableExprAST>(name);
    }

    // function call
    NextToken();
    std::vector<std::unique_ptr<ExprAST>> args;
    if (current_ != TOKEN_CHAR || current_char_ != ')') {
      while (true) {
        auto arg = ParseExpression();
        if (arg) {
          args.push_back(std::move(arg));
        } else {
          return nullptr;
        }

        if (current_ == TOKEN_CHAR && current_char_ == ')') {
          break;
        }

        if (current_ != TOKEN_CHAR || current_char_ != ',') {
          std::cerr << "Expected ')' or ',' in argument list" << std::endl;
          return nullptr;
        }
        NextToken();
      }
    }

    NextToken();
    return std::make_unique<CallExprAST>(name, std::move(args));
  }

  std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto e = std::make_unique<NumberExprAST>(numeric_value_);
    NextToken();
    return std::move(e);
  }

  std::unique_ptr<ExprAST> ParseParenExpr() {
    NextToken();
    auto e = ParseExpression();
    if (!e) {
      return nullptr;
    }

    if (current_ != TOKEN_CHAR || current_char_ != ')') {
      std::cerr << "Expected ')'" << std::endl;
      return nullptr;
    }
    NextToken();
    return e;
  }

  std::unique_ptr<ExprAST> ParseIfExpr() {
    NextToken();

    auto condition = ParseExpression();
    if (!condition) {
      std::cerr << "Expected condition" << std::endl;
      return nullptr;
    }

    if (current_ != TOKEN_THEN) {
      std::cerr << "Expected then keyword" << std::endl;
      return nullptr;
    }
    NextToken();

    auto then_expr = ParseExpression();
    if (!then_expr) {
      std::cerr << "Expected expression after then" << std::endl;
      return nullptr;
    }

    if (current_ != TOKEN_ELSE) {
      std::cerr << "Expected else keyword" << std::endl;
      return nullptr;
    }
    NextToken();
    auto else_expr = ParseExpression();
    if (!else_expr) {
      std::cerr << "Expected expression after else" << std::endl;
      return nullptr;
    }
    return std::make_unique<IfExprAST>(
        std::move(condition), std::move(then_expr), std::move(else_expr));
  }

  std::unique_ptr<ExprAST> ParseForExpr() {
    NextToken();
    if (current_ != TOKEN_IDENTIFIER) {
      std::cerr << "Expected an identifier after for keyword" << std::endl;
      return nullptr;
    }

    std::string id_name = identifier_;
    NextToken();

    if (current_ != TOKEN_CHAR || current_char_ != '=') {
      std::cerr << "Expected '=' after variable name" << std::endl;
      return nullptr;
    }
    NextToken();

    auto var_init = ParseExpression();
    if (!var_init) {
      return nullptr;
    }

    if (current_ != TOKEN_CHAR || current_char_ != ',') {
      std::cerr << "Expected ',' after variable init value" << std::endl;
      return nullptr;
    }
    NextToken();

    auto done_expr = ParseExpression();
    if (!done_expr) {
      std::cerr << "Expected done expression" << std::endl;
      return nullptr;
    }

    std::unique_ptr<ExprAST> step_expr;
    if (current_ == TOKEN_CHAR && current_char_ == ',') {
      NextToken();
      step_expr = ParseExpression();
      if (!step_expr) {
        return nullptr;
      }
    }

    if (current_ != TOKEN_IN) {
      std::cerr << "Expected 'in' keyword in for statement" << std::endl;
      return nullptr;
    }
    NextToken();

    auto body_expr = ParseExpression();
    if (!body_expr) {
      std::cerr << "Expected body expression" << std::endl;
      return nullptr;
    }
    return std::make_unique<ForExprAST>(
        id_name, std::move(var_init), std::move(done_expr),
        std::move(step_expr), std::move(body_expr));
  }

  std::unique_ptr<ExprAST> ParsePrimary() {
    switch (current_) {
      case TOKEN_IDENTIFIER:
        return ParseIdentifierExpr();
      case TOKEN_NUMBER:
        return ParseNumberExpr();
      case TOKEN_CHAR:
        if (current_char_ == '(') {
          return ParseParenExpr();
        }
        break;
      case TOKEN_IF:
        return ParseIfExpr();
      case TOKEN_FOR:
        return ParseForExpr();
      default:
        break;
    }

    // std::cout << "ParsePrimary: " << "index=" << index_ << "  token=" << current_ << " char=" << current_char_  << " identifier=" << identifier_ << std::endl;
    std::cerr << "unknown token when expecting an expression" << std::endl;
    return nullptr;
  }

  int GetOpPrecedence(char binop) {
    if (!isascii(binop)) {
      return -1;
    }

    if (!precedence.count(binop)) {
      return -1;
    }
    return precedence[binop];
  }

  std::unique_ptr<ExprAST> ParseBinaryOperationRHS(
      int precedence, std::unique_ptr<ExprAST> LHS) {
    while (true) {
      // std::cout << "current char=" << current_char_ << std::endl;
      int p = GetOpPrecedence(current_char_);
      if (p < precedence) {
        return LHS;
      }

      char binop = current_char_;
      NextToken();

      auto RHS = ParsePrimary();
      if (!RHS) {
        return nullptr;
      }

      int p2 = GetOpPrecedence(current_char_);
      if (p2 < p) {
        RHS = ParseBinaryOperationRHS(p + 1, std::move(RHS));
        if (!RHS) {
          return nullptr;
        }
      }

      LHS = std::make_unique<BinaryExprAST>(binop, std::move(LHS),
                                            std::move(RHS));
    }
  }

  std::unique_ptr<ExprAST> ParseExpression() {
    // std::cout << "ParseExpression: " << "index=" << index_ << "  token=" << current_ << " char=" << current_char_  << std::endl;
    auto LHS = ParsePrimary();
    if (!LHS) {
      return nullptr;
    }
    return ParseBinaryOperationRHS(0, std::move(LHS));
  }

  std::unique_ptr<FunctionAST> ParseDefinition() {
    NextToken();
    auto proto = ParsePrototype();
    if (!proto) {
      return nullptr;
    }

    auto e = ParseExpression();
    if (e) {
      return std::make_unique<FunctionAST>(std::move(proto), std::move(e));
    }
    return nullptr;
  }

  void HandleDefinition() {
    auto ast = ParseDefinition();
    if (ast) {
      auto* ir = ast->codegen();
      std::cout << "function definition: ";
      ir->print(llvm::outs());
      std::cout << "\n";
      ExitOnErr(jit->addModule(llvm::orc::ThreadSafeModule(
          std::move(module), std::move(llvm_context))));
      InitializeModuleAndManagers();
    } else {
      NextToken();
    }
  }

  std::unique_ptr<PrototypeAST> ParseExtern() {
    NextToken();
    return ParsePrototype();
  }

  void HandleExtern() {
    auto proto_ast = ParseExtern();
    if (proto_ast) {
      auto* ir = proto_ast->codegen();
      if (ir) {
        std::cout << "Read extern:" << std::endl;
        ir->print(llvm::outs());
        std::cout << '\n';
        function_protos[proto_ast->get_name()] = std::move(proto_ast);
      }
    } else {
      NextToken();
    }
  }

  std::unique_ptr<FunctionAST> ParseTopLevelExpr() {
    // std::cout << "ParseTopLevel" << index_ << ", token=" << current_ << " current char=" << current_char_ << std::endl;
    auto e = ParseExpression();
    if (e) {
      auto proto = std::make_unique<PrototypeAST>("__top_level_expr__",
                                                  std::vector<std::string>());
      return std::make_unique<FunctionAST>(std::move(proto), std::move(e));
    }
    return nullptr;
  }

  void HandleTopLevelExpression() {
    auto ast = ParseTopLevelExpr();
    if (ast) {
      if (ast->codegen()) {
        auto rt = jit->getMainJITDylib().createResourceTracker();

        auto tsm = llvm::orc::ThreadSafeModule(std::move(module),
                                               std::move(llvm_context));
        ExitOnErr(jit->addModule(std::move(tsm), rt));
        InitializeModuleAndManagers();

        auto expr_symbol = ExitOnErr(jit->lookup("__top_level_expr__"));

        auto fp = expr_symbol.toPtr<double (*)()>();
        std::cout << "toy-language evaluate: " << fp() << std::endl;
        ExitOnErr(rt->remove());
      }
    } else {
      NextToken();
    }
  }

  std::string code_;
  size_t index_;
  char current_char_, last_char_;
  Token current_;

  std::string identifier_;
  double numeric_value_;
};

void InitializeModuleAndManagers() {
  // Open a new context and module.
  llvm_context = std::make_unique<llvm::LLVMContext>();
  module = std::make_unique<llvm::Module>("toy-language", *llvm_context);
  module->setDataLayout(jit->getDataLayout());

  // Create a new builder for the module.
  ir_builder = std::make_unique<llvm::IRBuilder<>>(*llvm_context);

  // Create new pass and analysis managers.
  FPM = std::make_unique<llvm::FunctionPassManager>();
  LAM = std::make_unique<llvm::LoopAnalysisManager>();
  FAM = std::make_unique<llvm::FunctionAnalysisManager>();
  CGAM = std::make_unique<llvm::CGSCCAnalysisManager>();
  MAM = std::make_unique<llvm::ModuleAnalysisManager>();
  PIC = std::make_unique<llvm::PassInstrumentationCallbacks>();
  SI = std::make_unique<llvm::StandardInstrumentations>(*llvm_context, true);
  SI->registerCallbacks(*PIC, MAM.get());

  // Add transform passes.
  // Do simple "peephole" optimizations and bit-twiddling optzns.
  FPM->addPass(llvm::InstCombinePass());
  // Reassociate expressions.
  FPM->addPass(llvm::ReassociatePass());
  // Eliminate Common SubExpressions.
  FPM->addPass(llvm::GVNPass());
  // Simplify the control flow graph (deleting unreachable blocks, etc).
  FPM->addPass(llvm::SimplifyCFGPass());

  // Register analysis passes used in these transform passes.
  llvm::PassBuilder PB;
  PB.registerModuleAnalyses(*MAM);
  PB.registerFunctionAnalyses(*FAM);
  PB.crossRegisterProxies(*LAM, *FAM, *CGAM, *MAM);
}

std::string ReadFile(const std::string& filepath) {
  std::ifstream file(filepath);
  std::stringstream ss;
  ss << file.rdbuf();
  return ss.str();
}

void TestParse(const std::string& filepath) {
  std::string test1 = ReadFile(filepath);
  std::cout << "code: \n" << test1 << std::endl;
  Parser parser1(test1);
  parser1.Parse();
}

int main(void) {
  llvm::InitializeNativeTarget();
  llvm::InitializeNativeTargetAsmParser();
  llvm::InitializeNativeTargetAsmPrinter();

  jit = ExitOnErr(ToyLanguageJIT::Create());
  InitializeModuleAndManagers();

  precedence['<'] = precedence['>'] = 1 << 4;
  precedence['+'] = precedence['-'] = 1 << 8;
  precedence['*'] = precedence['/'] = 1 << 12;


  TestParse("./test1.txt");
  TestParse("./test2.txt");
  TestParse("./test3.txt");
  return 0;
}
