#include <cstring>
#include <iostream>

#include "xml_parser.h"

static void XMLCALL start_element(void *user_data, const XML_Char *name,
                                  const XML_Char **attrs) {
  ParserContext* context = (ParserContext*) user_data;

  for (int i = 0; i < context->depth; ++i) {
    std::cout << "  ";
  }

  std::cout << name;
  for (int i = 0; attrs[i]; i += 2) {
    std::cout << " " << attrs[i] << "=" << attrs[i + 1];
  }
  std::cout << std::endl;
  context->depth++;
}

static void XMLCALL end_element(void *user_data, const XML_Char *name) {
  ParserContext* context = (ParserContext*)user_data;
  (void)name;
  context->depth--;
}

XMLParser::XMLParser() : parser_(XML_ParserCreate(nullptr)) {
  if (parser_) {
    XML_SetUserData(parser_, &context_);
    XML_SetElementHandler(parser_, start_element, end_element);
  }
}

XMLParser::~XMLParser() { XML_ParserFree(parser_); }

void XMLParser::parse(const std::string &xml) {
  size_t offset = 0;
  bool done = false;
  do {
    auto buf = XML_GetBuffer(parser_, BUFSIZ);
    if (!buf) {
      std::cerr << "Couldn't allocate memeory for buffer" << std::endl;
      return;
    }

    size_t read = BUFSIZ;
    if (offset + read >= xml.length()) {
      read = xml.length() - offset;
      done = true;
    }
    std::memcpy(buf, xml.c_str() + offset, read);
    offset += read;

    if (XML_ParseBuffer(parser_, (int)read, done) == XML_STATUS_ERROR) {
      std::cerr << "Parse error at line " << XML_GetCurrentLineNumber(parser_)
                << ": " << XML_ErrorString(XML_GetErrorCode(parser_))
                << std::endl;
      return;
    }
  } while (!done);
}
