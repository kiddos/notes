#include <string>

#include "expat.h"

struct ParserContext {
  int depth;
};

class XMLParser {
 public:
  XMLParser();
  ~XMLParser();

  void parse(const std::string& xml);

 private:
  XML_Parser parser_;
  ParserContext context_;
};
