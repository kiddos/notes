#include "expat.h"
#include <string>

struct ParserContext {
  int depth;
};

class XMLParser {
 public:
  XMLParser();
  ~XMLParser();

  void parse(const std::string &xml);

 private:
  XML_Parser parser_;
  ParserContext context_;
};
