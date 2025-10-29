#include <zstd.h>

#include <filesystem>
#include <fstream>
#include <iostream>

std::string read_file(const std::string& filename) {
  auto size = std::filesystem::file_size(filename);
  std::string content(size, '\0');
  std::ifstream in(filename);
  in.read(&content[0], size);
  return content;
}

void* compress(void* data, size_t data_size, size_t& compressed_size) {
  size_t const output_size = ZSTD_compressBound(data_size);
  void* output = malloc(output_size);
  compressed_size = ZSTD_compress(output, output_size, data, data_size, 1);
  return output;
}

void* decompress(void* compressed, size_t compressed_size, size_t& decompressed_size) {
  size_t size = ZSTD_getFrameContentSize(compressed, compressed_size);
  void* decompressed = malloc((size_t)size);
  decompressed_size = ZSTD_decompress(decompressed, size, compressed, compressed_size);
  return decompressed;
}

int main(void) {
  std::string content = read_file("./20M.txt");
  std::cout << "file size: " << content.length() << std::endl;

  size_t compressed_size = 0;
  void* compressed = compress((void*)&content[0], content.length(), compressed_size);
  std::cout << "compress size: " << compressed_size << std::endl;

  size_t decompressed_size = 0;
  void* decompressed = decompress(compressed, compressed_size, decompressed_size);
  std::cout << "decompress size: " << decompressed_size << std::endl;

  std::ofstream f1("./20M.txt.zst");
  f1.write((char*)compressed, compressed_size);

  std::ofstream f2("./20M_1.txt");
  f2.write((char*)decompressed, decompressed_size);

  free(compressed);
  free(decompressed);
  return 0;
}
