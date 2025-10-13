#include <nlohmann/json.hpp>
#include <iostream>

int main(void) {
  // string to json
  std::string json_text = R"(
    {
      "pi": 3.141,
      "happy": true
    }
  )";

  nlohmann::json json = nlohmann::json::parse(json_text);
  json["value"] = 666;

  // json to string
  json_text = json.dump();
  std::cout << "json=" << json_text << std::endl;
  return 0;
}
