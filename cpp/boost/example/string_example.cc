#include <boost/algorithm/string.hpp>  // Includes all string algorithms
#include <iostream>
#include <string>
#include <vector>

using namespace boost::algorithm;

int main() {
  std::string s1 = "hello boost world";
  std::cout << "Original: " << s1 << std::endl;
  std::cout << "Uppercase Copy: " << to_upper_copy(s1) << std::endl;

  // In-place conversion
  to_lower(s1);
  std::cout << "In-place to_lower: " << s1 << std::endl;

  std::string s2 = "   \t  leading and trailing spaces  \n  ";
  std::string s2_trimmed = trim_copy(s2);
  std::cout << "Original (in quotes): \"" << s2 << "\"" << std::endl;
  std::cout << "Trimmed Copy (in quotes): \"" << s2_trimmed << "\""
            << std::endl;

  // In-place trimming
  trim(s2);
  std::cout << "In-place Trim (in quotes): \"" << s2 << "\"" << std::endl;

  std::string s3 = "Boost C++ Libraries";
  // Case-sensitive check
  std::cout << "Does s3 start with 'Boost'? " << std::boolalpha
            << starts_with(s3, "Boost") << std::endl;
  std::cout << "Does s3 contain 'c++'? " << std::boolalpha
            << contains(s3, "c++") << std::endl;

  // Case-insensitive check (using 'i' prefix)
  std::cout << "Does s3 (case-insensitive) contain 'libraries'? "
            << std::boolalpha << icontains(s3, "libraries") << std::endl;

  std::cout << "-----------------------" << std::endl;

  std::string s4 = "data-set-example";
  // Replace all hyphens with underscores
  std::string s4_replaced = replace_all_copy(s4, "-", "_");
  std::cout << "Original: " << s4 << std::endl;
  std::cout << "Replaced: " << s4_replaced << std::endl;

  // Erase all underscores (in-place)
  erase_all(s4_replaced, "_");
  std::cout << "After erase_all: " << s4_replaced << std::endl;

  std::cout << "--- Split and Join ---" << std::endl;
  std::string s5 = "item1; item2; item3; item4";
  std::vector<std::string> parts;

  // Split the string into a vector using ';' as a delimiter
  // is_any_of is a classification predicate
  split(parts, s5, is_any_of(";"), token_compress_on);

  std::cout << "Splitting \"" << s5 << "\":" << std::endl;
  for (const std::string& part : parts) {
    // Also a good place to demonstrate trimming on parts
    std::string trimmed_part = trim_copy(part);
    std::cout << "  - \"" << trimmed_part << "\"" << std::endl;
  }

  std::string s5_joined = join(parts, " | ");
  std::cout << "Joining parts with ' | ': " << s5_joined << std::endl;
  return 0;
}
