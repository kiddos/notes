#include <iostream>
#include <memory>
#include <string>

#include "eval/public/activation.h"
#include "eval/public/builtin_func_registrar.h"
#include "eval/public/cel_expr_builder_factory.h"
#include "eval/public/cel_expression.h"
#include "eval/public/cel_options.h"
#include "eval/public/cel_value.h"
#include "google/protobuf/arena.h"
#include "parser/parser.h"

int main() {
  using namespace google::api::expr::runtime;

  InterpreterOptions options;
  auto builder = CreateCelExpressionBuilder(options);

  std::string expression = "1 + 2 * 3";
  auto parse_status = google::api::expr::parser::Parse(expression);
  if (!parse_status.ok()) {
    std::cerr << "Parse failed: " << parse_status.status() << std::endl;
    return 1;
  }

  auto status = RegisterBuiltinFunctions(builder.get()->GetRegistry(), options);
  if (!status.ok()) {
    std::cerr << "Failed to register built-in functions: " << status
              << std::endl;
    return 1;
  }

  auto cel_expression =
      builder
          ->CreateExpression(&parse_status.value().expr(),
                             &parse_status.value().source_info())
          .value();

  google::protobuf::Arena arena;
  Activation activation;
  auto result = cel_expression->Evaluate(activation, &arena);

  if (result.ok()) {
    if (result->IsInt64()) {
      std::cout << "Evaluate value: " << result->Int64OrDie() << std::endl;
    }
  }

  return 0;
}
