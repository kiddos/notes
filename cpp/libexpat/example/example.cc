#include <expat.h>
#include <CLI/CLI.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Item {
  std::string name;
  std::vector<std::pair<std::string, std::string>> attributes;
  std::string content;
};

struct ParseContext {
  std::vector<Item> st;
  std::vector<Item> items;
};

static void XMLCALL start_element(void* user_data, const XML_Char* name,
                                  const XML_Char** attrs) {
  ParseContext* context = (ParseContext*)user_data;
  std::string start_tag = name;
  Item item;
  item.name = name;
  for (int i = 0; attrs[i]; i += 2) {
    std::pair<std::string, std::string> keyval;
    keyval.first = attrs[i];
    keyval.second = attrs[i+1];
    item.attributes.push_back(keyval);
  }

  context->st.push_back(item);
}

void XMLCALL data_handler(void *user_data, const XML_Char *s, int len) {
  ParseContext* context = (ParseContext*)user_data;
  if (!context->st.empty()) {
    std::string content(len, ' ');
    for (int i = 0; i < len; ++i) {
      content[i] = s[i];
    }
    context->st.back().content = content;
  }
}

static void XMLCALL end_element(void* user_data, const XML_Char* name) {
  ParseContext* context = (ParseContext*)user_data;

  std::string end_tag = name;
  if (context->st.size() && end_tag == context->st.back().name) {
    auto& item = context->st.back();
    std::cout << std::string(context->st.size(), ' ');
    std::cout << item.name << " ";
    for (auto [key, val] : item.attributes) {
      std::cout << key << "=" << val << " ";
    }
    if (item.content.length()) {
      std::cout << "content=" << item.content;
    }
    std::cout << std::endl;

    context->st.pop_back();
  }
}

int main(int argc, char* argv[]) {
  CLI::App app{"App description"};
  argv = app.ensure_utf8(argv);

  std::string filename = "";
  app.add_option("-f,--file", filename, "xml filename");
  CLI11_PARSE(app, argc, argv);

  XML_Parser parser = XML_ParserCreate(nullptr);
  if (!parser) {
    fprintf(stderr, "Couldn't allocate memory for parser\n");
    return 1;
  }

  ParseContext context;
  XML_SetUserData(parser, &context);
  XML_SetCharacterDataHandler(parser, data_handler);
  XML_SetElementHandler(parser, start_element, end_element);

  std::ifstream xml_file(filename);

  int done = 0;
  do {
    void* buf = XML_GetBuffer(parser, BUFSIZ);
    if (!buf) {
      fprintf(stderr, "Couldn't allocate memory for buffer\n");
      XML_ParserFree(parser);
      return 1;
    }

    int len = xml_file.readsome((char*)buf, BUFSIZ);
    if (xml_file.eof() || len == 0) {
      done = true;
    }

    if (XML_ParseBuffer(parser, len, done) == XML_STATUS_ERROR) {
      std::cerr << "Parse error at line " << XML_GetCurrentLineNumber(parser)
          << ": " << XML_ErrorString(XML_GetErrorCode(parser)) << std::endl;
      XML_ParserFree(parser);
      return 1;
    }
  } while (!done);

  XML_ParserFree(parser);
  return 0;
}
