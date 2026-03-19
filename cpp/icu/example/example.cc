#include <unicode/locid.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>

#include <iostream>

int main(void) {
  icu::UnicodeString text = icu::UnicodeString::fromUTF8("straße");
  icu::Locale locale("de", "DE");

  text.toUpper(locale);

  std::string result;
  text.toUTF8String(result);
  std::cout << "Original: straße" << std::endl;
  std::cout << "Uppercase: " << result << std::endl;
  return 0;
}
