#include <zlib.h>

#include <iostream>
#include <string>
#include <vector>

bool compress_data(const std::string& data,
                   std::vector<unsigned char>& compressed_data) {
  uLongf compressed_len = compressBound(data.length());
  compressed_data.resize(compressed_len);

  Bytef* output = compressed_data.data();
  const Bytef* source = reinterpret_cast<const Bytef*>(data.data());
  int result = compress(output, &compressed_len, source, data.length());

  if (result == Z_OK) {
    compressed_data.resize(compressed_len);
    return true;
  } else {
    std::cerr << "Error during compression: " << result << std::endl;
    return false;
  }
}

bool decompress_data(const std::vector<unsigned char>& compressed_data,
                     std::string& decompressed_data, uLongf original_size) {
  decompressed_data.resize(original_size);
  uLongf decompressed_len = original_size;

  Bytef* output = reinterpret_cast<Bytef*>(decompressed_data.data());
  const Bytef* source = reinterpret_cast<const Bytef*>(compressed_data.data());
  int result = uncompress(output, &decompressed_len, source,
                          compressed_data.size());

  if (result == Z_OK) {
    decompressed_data.resize(decompressed_len);
    return true;
  } else {
    std::cerr << "Error during decompression: " << result << std::endl;
    return false;
  }
}

int main() {
  std::string original_text =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
      "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim "
      "veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea "
      "commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
      "velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
      "occaecat cupidatat non proident, sunt in culpa qui officia deserunt "
      "mollit anim id est laborum.";
  std::cout << "Original text: " << original_text << std::endl;
  std::cout << "Original size: " << original_text.length() << " bytes"
            << std::endl;

  std::vector<unsigned char> compressed_output;
  if (compress_data(original_text, compressed_output)) {
    std::cout << "Compressed size: " << compressed_output.size() << " bytes"
              << std::endl;

    std::string decompressed_output;
    if (decompress_data(compressed_output, decompressed_output,
                        original_text.length())) {
      std::cout << "Decompressed text: " << decompressed_output << std::endl;
      if (original_text == decompressed_output) {
        std::cout << "Compression and decompression successful! Data matches."
                  << std::endl;
      } else {
        std::cout << "Decompressed data does NOT match original." << std::endl;
      }
    }
  }
  return 0;
}
