#include <iostream>
#include <rttr/registration>

using namespace rttr;

struct DataEntry {
  int key, value;

  DataEntry(int key, int value) : key(key), value(value) {}

  void zero() {
    key = 0;
    value = 0;
  }
};

RTTR_REGISTRATION {
  registration::class_<DataEntry>("DataEntry")
      .constructor<int, int>()
      .property("key", &DataEntry::key)
      .property("value", &DataEntry::value)
      .method("zero", &DataEntry::zero);
}

int main(void) {
  type t = type::get<DataEntry>();
  for (auto& prop : t.get_properties()) {
    std::cout << "property name: " << prop.get_name() << std::endl;
  }
  for (auto& meth : t.get_methods()) {
    std::cout << "method name: " << meth.get_name() << std::endl;
  }
  return 0;
}
