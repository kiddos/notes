#ifndef AST_H
#define AST_H

#include "llvm/IR/Value.h"

class ExprAST {
 public:
  virtual ~ExprAST() = default;
  virtual llvm::Value* codegen() = 0;
};

class NumberExprAST : public ExprAST {
 public:
  NumberExprAST(double val) : val_(val) {}
  llvm::Value* codegen() override;

 private:
  double val_;
};

class VariableExprAST : public ExprAST {
 public:
  VariableExprAST(const std::string& Name) : name_(Name) {}
  llvm::Value* codegen() override;

 private:
  std::string name_;
};

class BinaryExprAST : public ExprAST {
 public:
  BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                std::unique_ptr<ExprAST> RHS)
      : op_(Op), LHS_(std::move(LHS)), RHS_(std::move(RHS)) {}

  llvm::Value* codegen() override;

 private:
  char op_;
  std::unique_ptr<ExprAST> LHS_, RHS_;
};

class CallExprAST : public ExprAST {
 public:
  CallExprAST(const std::string& Callee,
              std::vector<std::unique_ptr<ExprAST>> Args)
      : callee_(Callee), args_(std::move(Args)) {}

  llvm::Value* codegen() override;

 private:
  std::string callee_;
  std::vector<std::unique_ptr<ExprAST>> args_;
};

class IfExprAST : public ExprAST {
 public:
  IfExprAST(std::unique_ptr<ExprAST> Cond, std::unique_ptr<ExprAST> Then,
            std::unique_ptr<ExprAST> Else)
      : cond_(std::move(Cond)),
        then_(std::move(Then)),
        else_(std::move(Else)) {}

  llvm::Value* codegen() override;

 private:
  std::unique_ptr<ExprAST> cond_, then_, else_;
};

class ForExprAST : public ExprAST {
 public:
  ForExprAST(const std::string& VarName, std::unique_ptr<ExprAST> Start,
             std::unique_ptr<ExprAST> End, std::unique_ptr<ExprAST> Step,
             std::unique_ptr<ExprAST> Body)
      : varname_(VarName),
        start_(std::move(Start)),
        end_(std::move(End)),
        step_(std::move(Step)),
        body_(std::move(Body)) {}

  llvm::Value* codegen() override;

 private:
  std::string varname_;
  std::unique_ptr<ExprAST> start_, end_, step_, body_;
};

class PrototypeAST {
 public:
  PrototypeAST(const std::string& Name, std::vector<std::string> Args)
      : name_(Name), args_(std::move(Args)) {}

  llvm::Function* codegen();
  const std::string& get_name() const { return name_; }

 private:
  std::string name_;
  std::vector<std::string> args_;
};

class FunctionAST {
 public:
  FunctionAST(std::unique_ptr<PrototypeAST> Proto,
              std::unique_ptr<ExprAST> Body)
      : proto_(std::move(Proto)), body_(std::move(Body)) {}

  llvm::Function* codegen();

 private:
  std::unique_ptr<PrototypeAST> proto_;
  std::unique_ptr<ExprAST> body_;
};

#endif /* end of include guard: AST_H */
