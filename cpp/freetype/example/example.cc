#include <ft2build.h>
#include <png.h>

#include <CLI/CLI.hpp>
#include <iostream>
#include <vector>
#include FT_FREETYPE_H

void render_string(FT_Face face, std::string text, int width, int height,
                   std::vector<uint8_t>& pixels) {
  int pen_x = 0;
  int pen_y = 64;  // Vertical offset so letters don't go off the top

  for (char c : text) {
    if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
      continue;
    }

    FT_GlyphSlot slot = face->glyph;
    FT_Bitmap& bitmap = slot->bitmap;
    int x_start = pen_x + slot->bitmap_left;
    int y_start = pen_y - slot->bitmap_top;

    for (int row = 0; row < (int)bitmap.rows; ++row) {
      for (int col = 0; col < (int)bitmap.width; ++col) {
        int canvas_x = x_start + col;
        int canvas_y = y_start + row;
        if (canvas_x >= 0 && canvas_x < width && canvas_y >= 0 &&
            canvas_y < height) {
          pixels[canvas_y * width + canvas_x] =
              bitmap.buffer[row * bitmap.pitch + col];
        }
      }
    }
    pen_x += (slot->advance.x >> 6);
  }
}

bool save_png(const std::string& filename, int width, int height,
              std::vector<uint8_t>& pixels) {
  FILE* fp = fopen(filename.c_str(), "wb");
  if (!fp) return false;

  png_structp png_ptr =
      png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr) {
    fclose(fp);
    return false;
  }

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) {
    png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
    fclose(fp);
    return false;
  }

  // Set up error handling (required by libpng's use of setjmp)
  if (setjmp(png_jmpbuf(png_ptr))) {
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    return false;
  }

  png_init_io(png_ptr, fp);

  // PNG_COLOR_TYPE_GRAY is 1 byte per pixel
  png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_GRAY,
               PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE,
               PNG_FILTER_TYPE_BASE);

  png_write_info(png_ptr, info_ptr);

  std::vector<png_bytep> row_pointers(height);
  for (int y = 0; y < height; y++) {
    row_pointers[y] = (png_bytep)&pixels[y * width];
  }

  png_write_image(png_ptr, row_pointers.data());
  png_write_end(png_ptr, NULL);

  fclose(fp);
  png_destroy_write_struct(&png_ptr, &info_ptr);

  return true;
}

int main(int argc, char* argv[]) {
  CLI::App app{"freetype example"};
  argv = app.ensure_utf8(argv);

  std::string fontfile = "";
  app.add_option("-f,--file", fontfile, "font file");
  CLI11_PARSE(app, argc, argv);

  FT_Library library;
  FT_Face face;
  if (FT_Init_FreeType(&library)) {
    std::cerr << "Could not init FreeType Library" << std::endl;
    return 1;
  }

  if (FT_New_Face(library, fontfile.c_str(), 0, &face)) {
    std::cerr << "Failed to load font" << std::endl;
    return 1;
  }

  // 16 points at 300 DPI
  FT_Set_Char_Size(face, 0, 16 * 64, 300, 300);
  // or set height to 48 pixels. 0 for width means "scale proportionally"
  // FT_Set_Pixel_Sizes(face, 0, 48);

  int width = 500;
  int height = 100;
  std::vector<uint8_t> pixels(width * height);
  render_string(face, "Hello World!", width, height, pixels);

  save_png("font.png", width, height, pixels);

  FT_Done_Face(face);
  FT_Done_FreeType(library);
  return 0;
}
