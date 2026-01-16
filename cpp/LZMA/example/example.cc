#include <string>
#include <iostream>

#include "Alloc.h"
#include "LzmaDec.h"
#include "LzmaEnc.h"

int main(void) {
  const std::string data =
      "Hello, this is a test string to demonstrate LZMA C API!";
  size_t src_len = data.length() + 1;

  CLzmaEncProps props;
  LzmaEncProps_Init(&props);
  props.dictSize = 1 << 16;  // 64 KB dictionary
  props.writeEndMark = 0;    // 0 = no EOS mark

  SizeT props_size = LZMA_PROPS_SIZE;
  Byte props_encoded[LZMA_PROPS_SIZE];

  // Estimate max compressed size (usually input + 5% + some bytes)
  SizeT dest_len = src_len + src_len / 3 + 128;
  Byte* dest_body = (Byte*)malloc(dest_len);

  SRes res =
      LzmaEncode(dest_body, &dest_len, (const Byte*)data.c_str(), src_len, &props,
                 props_encoded, &props_size, 0, NULL, &g_Alloc, &g_Alloc);

  if (res != SZ_OK) {
    std::cerr << "Compression failed" << std::endl;
    return 1;
  }
  std::cout << "Compress " << src_len << " -> " << dest_len << std::endl;

  // decompress
  SizeT output_size_full = src_len;  // You must know the uncompressed size
  Byte* output_buffer = (Byte*)malloc(output_size_full);
  SizeT in_size_consumed = dest_len;
  ELzmaStatus status;

  res = LzmaDecode(output_buffer, &output_size_full, dest_body, &in_size_consumed,
                   props_encoded, props_size, LZMA_FINISH_ANY, &status, &g_Alloc);

  if (res == SZ_OK) {
    std::cout << "Decompress data: " << (char*)output_buffer << std::endl;
  } else {
    std::cerr << "Decompression failed" << std::endl;
  }

  free(dest_body);
  free(output_buffer);
  return 0;
}
