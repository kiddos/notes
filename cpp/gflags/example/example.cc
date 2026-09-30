#include <gflags/gflags.h>

#include <iostream>

// Define flags (Type, Name, Default Value, Description)
DEFINE_bool(verbose, false, "Enable verbose output");
DEFINE_string(name, "World", "The name to greet");
DEFINE_int32(count, 1, "Number of times to print the greeting");

int main(int argc, char* argv[]) {
  gflags::SetUsageMessage(
      "A simple program demonstrating gflags usage.\n"
      "Usage: ./example [flags]");

  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if (FLAGS_verbose) {
    std::cout << "[INFO] Running with count = " << FLAGS_count << "\n";
  }

  for (int i = 0; i < FLAGS_count; ++i) {
    std::cout << "Hello, " << FLAGS_name << "!\n";
  }

  gflags::ShutDownCommandLineFlags();
  return 0;
}
