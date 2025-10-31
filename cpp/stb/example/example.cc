#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE2_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <string>
#include <vector>

#include "stb_image.h"
#include "stb_image_resize2.h"
#include "stb_image_write.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: stb_example <image_file>\n";
    return 1;
  }

  std::string filename = argv[1];
  int width, height, channels;

  // Load image
  unsigned char* data =
      stbi_load(filename.c_str(), &width, &height, &channels, 0);

  if (!data) {
    std::cerr << "Failed to load image: " << filename << "\n";
    return 1;
  }

  std::cout << "Loaded image: " << filename << "\n";
  std::cout << "  Width: " << width << "\n";
  std::cout << "  Height: " << height << "\n";
  std::cout << "  Channels: " << channels << "\n";

  // Example: Access first pixel
  unsigned char r = data[0];
  unsigned char g = data[1];
  unsigned char b = data[2];
  std::cout << "First pixel RGB = (" << (int)r << ", " << (int)g << ", "
            << (int)b << ")\n";

  int new_width = width / 2;
  int new_height = height / 2;

  std::vector<unsigned char> resized(new_width * new_height * channels);
  if (!stbir_resize_uint8_linear(data, width, height, 0, resized.data(),
                                 new_width, new_height, 0,
                                 (stbir_pixel_layout)channels)) {
    std::cerr << "Resize failed!\n";
    stbi_image_free(data);
    return 1;
  }

  std::cout << "Resized image to " << new_width << "x" << new_height << "\n";

  // Save resized image as jpg
  if (!stbi_write_jpg("resized.jpg", new_width, new_height, channels,
                      resized.data(), new_width * channels)) {
    std::cerr << "Failed to save resized.jpg\n";
  } else {
    std::cout << "Saved resized.jpg\n";
  }

  if (!stbi_write_png("resized.png", new_width, new_height, channels,
                      resized.data(), new_width * channels)) {
    std::cerr << "Failed to save resized.png\n";
  } else {
    std::cout << "Saved resized.png\n";
  }

  stbi_image_free(data);
  return 0;
}
