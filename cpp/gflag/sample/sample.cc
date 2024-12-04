#include <gflags/gflags.h>
#include <iostream>

// Define command-line flags
DEFINE_string(operation, "add",
              "Operation to perform: add, subtract, multiply, divide");
DEFINE_double(operand1, 0.0, "First operand");
DEFINE_double(operand2, 0.0, "Second operand");

int main(int argc, char *argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // Perform the requested operation
  double result = 0.0;
  if (FLAGS_operation == "add") {
    result = FLAGS_operand1 + FLAGS_operand2;
  } else if (FLAGS_operation == "subtract") {
    result = FLAGS_operand1 - FLAGS_operand2;
  } else if (FLAGS_operation == "multiply") {
    result = FLAGS_operand1 * FLAGS_operand2;
  } else if (FLAGS_operation == "divide") {
    if (FLAGS_operand2 != 0.0) {
      result = FLAGS_operand1 / FLAGS_operand2;
    } else {
      std::cerr << "Error: Division by zero" << std::endl;
      return 1;
    }
  } else {
    std::cerr << "Error: Unsupported operation '" << FLAGS_operation << "'."
              << std::endl;
    return 1;
  }
  std::cout << "Result: " << result << std::endl;

  // Clean up and return
  gflags::ShutDownCommandLineFlags();
  return 0;
}
