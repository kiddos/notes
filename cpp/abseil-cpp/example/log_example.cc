#include <absl/log/initialize.h>
#include <absl/log/log.h>
#include <absl/log/log_sink_registry.h>

#include <iostream>

class StdoutLogSink : public absl::LogSink {
 public:
  StdoutLogSink() {}

  void Send(const absl::LogEntry& entry) override {
    std::cout << entry.text_message_with_prefix_and_newline() << std::flush;
  }
};

int main(void) {
  absl::InitializeLog();
  StdoutLogSink logsink;
  absl::AddLogSink(&logsink);

  LOG(INFO) << "logging...";
  return 0;
}
