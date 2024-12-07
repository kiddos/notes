#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main() {
  // Input string containing sample email addresses
  std::string input =
      "Here are some emails: alice@example.com, bob.smith@company.org, "
      "charlie123@mail.net.";

  // Regex pattern for matching email addresses
  boost::regex email_pattern(
      R"(([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}))");

  // Search using regex
  boost::sregex_iterator begin(input.begin(), input.end(), email_pattern);
  boost::sregex_iterator end;

  std::cout << "Found email addresses:\n";

  for (boost::sregex_iterator i = begin; i != end; ++i) {
    std::cout << i->str() << std::endl;
  }
  return 0;
}
