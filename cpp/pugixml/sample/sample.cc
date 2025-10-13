#include <iostream>
#include <pugixml.hpp>

int main(void) {
  std::string source =
      "<note id=\"1\"><to>Tove</to><from>Jani</from><body>Don't forget me this "
      "weekend!</body></note>";
  pugi::xml_document doc;
  // load from file
  // pugi::xml_parse_result result = doc.load_file("data.xml");
  pugi::xml_parse_result result = doc.load_string(source.c_str());
  if (result) {
    pugi::xpath_node_set to = doc.select_nodes("/note/to");
    for (auto it = to.begin(); it != to.end(); ++it) {
      pugi::xpath_node node = *it;
      std::cout << "to=" << node.node().text().get() << std::endl;
    }

    pugi::xpath_node_set from = doc.select_nodes("/note/from");
    for (auto it = from.begin(); it != from.end(); ++it) {
      pugi::xpath_node node = *it;
      std::cout << "from=" << node.node().text().get() << std::endl;
    }
  }
  return 0;
}
