#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

int main(void) {
  YAML::Node config = YAML::Node();
  config["key"] = "value";

  std::ofstream fout("config.yaml");
  fout << config;
  fout << std::flush;
  fout.close();

  config = YAML::LoadFile("config.yaml");

  if (config["key"]) {
    std::string value = config["key"].as<std::string>();
    std::cout << value << std::endl;
  }
  return 0;
}
