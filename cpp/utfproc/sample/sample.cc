#include <utf8proc.h>

#include <cstdlib>
#include <iostream>
#include <string>

std::string normalize_nfc(const std::string& input) {
  // utf8proc functions use its own utf8proc_uint8_t, which is typically
  // unsigned char
  const utf8proc_uint8_t* input_bytes = (const utf8proc_uint8_t*)input.c_str();
  // utf8proc_NFC allocates memory for the result, which must be freed.
  utf8proc_uint8_t* output_bytes = utf8proc_NFC(input_bytes);
  if (!output_bytes) {
    return "";
  }

  std::string result((char*)output_bytes);
  std::free(output_bytes);
  return result;
}

int main() {
  std::string composed_e = "résumé";
  std::string decomposed_e = "re\x73\x75\x6d\x65\xCC\x81";  // "r e s u m e ́"

  std::cout << "--- UTF-8 Normalization Example (NFC) ---" << std::endl;
  std::cout << "Original (Composed): " << composed_e << std::endl;
  std::cout << "Original (Decomposed): " << decomposed_e << std::endl;
  std::cout << "\n";

  std::string normalized_result = normalize_nfc(decomposed_e);

  std::cout << "Normalized (NFC) Result: " << normalized_result << std::endl;

  if (normalized_result == composed_e) {
    std::cout << "Success: The decomposed string was correctly normalized to "
                 "the composed form."
              << std::endl;
  } else {
    std::cout
        << "Error: Normalization failed or produced a non-identical result."
        << std::endl;
  }

  return 0;
}
