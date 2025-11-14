#include <png.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

const int WIDTH = 100;
const int HEIGHT = 100;
const int PIXEL_SIZE = 3;
const int BIT_DEPTH = 8;

// The custom chunk type name.
// This ensures other PNG viewers will safely ignore it.
const char CUSTOM_CHUNK_TYPE[] = "tESt";

void write_png_with_custom_chunk(const std::string& filename,
                                 const std::vector<png_byte>& image_data,
                                 const std::string& hidden) {
  FILE* fp = fopen(filename.c_str(), "wb");
  if (!fp) {
    std::cerr << "Error: Could not open file " << filename << " for writing."
              << std::endl;
    return;
  }

  png_structp png_ptr =
      png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
  if (!png_ptr) {
    std::cerr << "Error: Could not allocate write struct." << std::endl;
    fclose(fp);
    return;
  }

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) {
    std::cerr << "Error: Could not allocate info struct." << std::endl;
    png_destroy_write_struct(&png_ptr, (png_infopp)nullptr);
    fclose(fp);
    return;
  }

  // Set up standard I/O
  png_init_io(png_ptr, fp);

  // image header information
  png_set_IHDR(png_ptr, info_ptr, WIDTH, HEIGHT, BIT_DEPTH,
               PNG_COLOR_TYPE_RGB,  // No alpha channel
               PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
               PNG_FILTER_TYPE_DEFAULT);

  // png_unknown_chunk allows libpng to read, store, and write
  // the data for any chunk that isn't part of the standard
  png_unknown_chunk custom_chunk;
  memcpy(custom_chunk.name, CUSTOM_CHUNK_TYPE, 4);
  custom_chunk.data =
      reinterpret_cast<png_bytep>(const_cast<char*>(hidden.data()));
  custom_chunk.size = hidden.length();
  custom_chunk.location = PNG_HAVE_IHDR;
  png_set_unknown_chunks(png_ptr, info_ptr, &custom_chunk, 1);

  png_write_info(png_ptr, info_ptr);

  std::vector<png_bytep> row_pointers(HEIGHT);
  const int row_bytes = WIDTH * PIXEL_SIZE;
  for (int y = 0; y < HEIGHT; ++y) {
    row_pointers[y] = const_cast<png_bytep>(&image_data[y * row_bytes]);
  }

  png_write_image(png_ptr, row_pointers.data());
  png_write_end(png_ptr, NULL);
  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose(fp);

  std::cout << "Successfully wrote PNG file: " << filename << std::endl;
}

std::vector<png_byte> create_white_image_data() {
  std::vector<png_byte> image_data(WIDTH * HEIGHT * PIXEL_SIZE);
  std::fill(image_data.begin(), image_data.end(), 255);
  return image_data;
}

void read_custom_chunk(const std::string& filename) {
  FILE* fp = fopen(filename.c_str(), "rb");
  if (!fp) {
    return;
  }

  png_byte header[8];
  fread(header, 1, 8, fp);
  // Check if the signature matches
  if (png_sig_cmp(header, 0, 8)) {
    fclose(fp);
    return;
  }
  png_structp png_ptr =
      png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
  if (!png_ptr) {
    fclose(fp);
    return;
  }

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) {
    png_destroy_read_struct(&png_ptr, NULL, NULL);
    fclose(fp);
    return;
  }

  png_init_io(png_ptr, fp);

  png_set_sig_bytes(png_ptr, 8);

  png_set_keep_unknown_chunks(png_ptr, PNG_HANDLE_CHUNK_ALWAYS,
                              (png_const_bytep)CUSTOM_CHUNK_TYPE, 1);
  png_read_info(png_ptr, info_ptr);

  png_unknown_chunkp unknown_chunks;
  int ret = png_get_unknown_chunks(png_ptr, info_ptr, &unknown_chunks);
  for (int i = 0; i < ret; ++i) {
    // Check for our specific chunk type
    if (memcmp(unknown_chunks[i].name, CUSTOM_CHUNK_TYPE, 4) == 0) {
      // Extract the data
      std::string raw_data(
          reinterpret_cast<const char*>(unknown_chunks[i].data),
          unknown_chunks[i].size);

      std::cout << "\nFound Custom Chunk Data:" << std::endl;
      std::cout << "  Chunk Type: " << CUSTOM_CHUNK_TYPE << std::endl;
      std::cout << "  Raw Data: " << raw_data << std::endl;
    }
  }

  png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
  fclose(fp);
}

int main() {
  std::vector<png_byte> image = create_white_image_data();
  std::string hidden = "this is a hidden message";
  write_png_with_custom_chunk("hidden.png", image, hidden);
  read_custom_chunk("hidden.png");
  return 0;
}
