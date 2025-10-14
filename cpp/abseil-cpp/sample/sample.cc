#include <iostream>
#include <string>
#include <vector>

#include <absl/strings/str_join.h>
#include <absl/container/flat_hash_map.h>

int main(void) {
  std::vector<std::string> words = {"This", "is", "a", "sentence"};
  std::string sentence = absl::StrJoin(words, " ");
  std::cout << sentence << std::endl;

  absl::flat_hash_map<std::string, std::string> data;
  data["key"] = "value";
  return 0;
}
