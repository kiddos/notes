#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>

#include <CLI/CLI.hpp>
#include <cstdlib>
#include <memory>
#include <string>

int main(int argc, char* argv[]) {
  CLI::App app{"tesseract example"};
  argv = app.ensure_utf8(argv);

  std::string image_path;
  app.add_option("-f,--file", image_path, "input image file");
  CLI11_PARSE(app, argc, argv);

  setenv("TESSDATA_PREFIX", "./_deps/tesseract-best-src/", 1);

  std::unique_ptr<tesseract::TessBaseAPI> api(new tesseract::TessBaseAPI());
  if (api->Init(nullptr, "eng")) {
    std::cerr << "fail to initialize tesseract" << std::endl;
    return 1;
  }

  PIX* image = pixRead(image_path.c_str());
  if (!image) {
    std::cerr << "Error: Could not read image file." << std::endl;
    api->End();
    return 1;
  }

  api->SetImage(image);
  std::string result = api->GetUTF8Text();

  std::cout << "OCR result: \n" << result << std::endl;

  pixDestroy(&image);
  api->End();
  return 0;
}
