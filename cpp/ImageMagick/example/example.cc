#include <Magick++.h>

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  Magick::InitializeMagick(*argv);

  Magick::Image image;
  try {
    image.read("test.png");
    image.crop(Magick::Geometry(100, 100, 100, 100));
    image.write("output.png");
  } catch (Magick::Exception& err) {
    std::cerr << "Caught exception: " << err.what() << std::endl;
  }
  return 0;
}
