#include <filesystem>
#include <glog/logging.h>
#include <iostream>

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  const std::string log_dir = LOG_DIR;
  FLAGS_log_dir = LOG_DIR;
  if (!std::filesystem::exists(log_dir)) {
    std::filesystem::create_directory(log_dir);
    std::cout << "Log directory created: " << log_dir << std::endl;
  }

  LOG(INFO) << "This is an info message.";
  LOG(WARNING) << "This is a warning message.";
  LOG(ERROR) << "This is an error message.";

  google::ShutdownGoogleLogging();
  return 0;
}
