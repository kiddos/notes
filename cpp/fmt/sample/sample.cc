#include <fmt/chrono.h>
#include <fmt/ranges.h>

#include <iostream>

int main() {
  auto now = std::chrono::system_clock::now();
  fmt::print("Date and time: {}\n", now);
  fmt::print("Time: {:%H:%M}\n", now);

  std::vector<int> v = {1, 2, 3};
  fmt::print("{}\n", v);

  std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");

  std::cout << s << std::endl;
  return 0;
}
