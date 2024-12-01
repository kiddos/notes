#include "xml_parser.h"
#include <fstream>
#include <string>

int main(void) {
  XMLParser parser;
  std::ifstream file("./sample3.xml");
  std::string xml((std::istreambuf_iterator<char>(file)),
                  std::istreambuf_iterator<char>());

  parser.parse(xml);
  return 0;
}
