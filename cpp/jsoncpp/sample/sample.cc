#include <iostream>
#include <json/json.h>

int main() {
  Json::Value root;
  root["name"] = "John Doe";
  root["age"] = 30;

  Json::StreamWriterBuilder builder;
  builder["indentation"] = "  ";
  const std::string json = Json::writeString(builder, root);
  std::cout << json << std::endl;
  return 0;
}
