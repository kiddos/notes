#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/string.hpp>
#include <string>
#include <fstream>

struct Record {
  int x, y;
  float z;
  std::string s;
  std::unordered_map<std::string, std::string> data;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(x, y, z, s, data);
  }
};

int main(void) {
  Record r;
  r.x = 10;
  r.y = 20;
  r.z = 30.0f;
  r.s = "string";
  r.data["key"] = "value";

  std::ofstream output("out.cereal", std::ios::binary);
  cereal::BinaryOutputArchive output_archive(output);
  output_archive(r);
  output.flush();
  output.close();

  std::ifstream input("out.cereal", std::ios::binary);
  cereal::BinaryInputArchive input_archive(input);

  Record r2;
  input_archive(r2);
  input.close();

  std::ofstream json_output("out.json");
  cereal::JSONOutputArchive json_output_archive(json_output);
  json_output_archive(r2);
  json_output.flush();
  json_output.close();
  return 0;
}
