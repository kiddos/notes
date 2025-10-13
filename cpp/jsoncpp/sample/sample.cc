#include <json/json.h>

#include <iostream>

int main() {
  Json::Value root;
  root["name"] = "John Doe";
  root["age"] = 30;

  // json to string
  Json::StreamWriterBuilder writer_builder;
  writer_builder["indentation"] = "  ";
  std::string json = Json::writeString(writer_builder, root);
  std::cout << json << std::endl;

  // string to json
  JSONCPP_STRING err;
  Json::Value value;
  Json::CharReaderBuilder reader_builder;
  const std::unique_ptr<Json::CharReader> reader(
      reader_builder.newCharReader());
  if (!reader->parse(json.c_str(), json.c_str() + json.length(), &value,
                     &err)) {
    std::cout << "error: " << err << std::endl;
  }

  return 0;
}
