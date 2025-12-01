#include <tsl/robin_map.h>
#include <tsl/robin_set.h>

int main(void) {
  tsl::robin_map<std::string, int> m;
  tsl::robin_set<int> s;

  m["data"] = 10;
  s.insert(100);
  return 0;
}
