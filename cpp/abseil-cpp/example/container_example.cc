#include <absl/container/flat_hash_map.h>

#include <string>

int main(void) {
  absl::flat_hash_map<std::string, std::string> data;
  data["key"] = "value";
  return 0;
}
