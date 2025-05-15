#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"

int main(void) {
  std::vector<std::string> words = {"This", "is", "a", "sentence"};
  std::string sentence = absl::StrJoin(words, " ");
  std::cout << sentence << std::endl;
  return 0;
}
