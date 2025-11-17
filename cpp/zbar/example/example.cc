#include <string>
#include <iostream>
#include <stb_image.h>
#include <zbar.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: example <image_file>\n";
    return 1;
  }

  std::string filename = argv[1];
  int width, height, channels;

  // Load image
  unsigned char* data =
      stbi_load(filename.c_str(), &width, &height, &channels, 1);

  if (!data) {
    std::cerr << "Failed to load image: " << filename << "\n";
    return 1;
  }

  zbar::zbar_image_scanner_t *scanner = zbar::zbar_image_scanner_create();
  zbar::zbar_image_scanner_set_config(scanner, zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

  zbar::zbar_image_t *image = zbar::zbar_image_create();
  zbar_image_set_format(image, zbar_fourcc('Y', '8', '0', '0'));
  zbar_image_set_size(image, width, height);
  zbar_image_set_data(image, data, width * height, nullptr);

  int n = zbar_scan_image(scanner, image);
  if (n > 0) {
    const zbar::zbar_symbol_t *symbol = zbar_image_first_symbol(image);
    for (; symbol; symbol = zbar_symbol_next(symbol)) {
      zbar::zbar_symbol_type_t type = zbar_symbol_get_type(symbol);
      const char *data = zbar_symbol_get_data(symbol);
      std::cout << "Found symbol:" << std::endl;
      std::cout << "  Type: **" << zbar_get_symbol_name(type) << "**" << std::endl;
      std::cout << "  Data: **" << data << "**" << std::endl;
    }
  } else {
    std::cout << "No barcode found." << std::endl;
  }

  stbi_image_free(data);
  zbar_image_destroy(image);
  zbar_image_scanner_destroy(scanner);
  return 0;
}
