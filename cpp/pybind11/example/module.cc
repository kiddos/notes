#include <pybind11/pybind11.h>
#include <sys/sysinfo.h>
#include <fmt/core.h>

#include <string>
#include <list>
#include <unordered_map>
#include <map>

std::string get_memory_info() {
  struct sysinfo info;
  if (sysinfo(&info) == 0) {
    long total = info.totalram / (1024 * 1024);
    long free = info.freeram / (1024 * 1024);
    return fmt::format("Total RAM: {}MB\nFree RAM: {}\n", total, free);
  } else {
    return "";
  }
}

template <typename K, typename V>
struct DataItem {
  K key;
  V value;
  int use_count;
  DataItem(K key, V value, int use_count)
      : key(key), value(value), use_count(use_count) {}
};

template <typename K, typename V>
class LFUCache {
 public:
  LFUCache(int capacity) : capacity_(capacity) {}

  V get(K key) {
    if (!pointer_.count(key)) {
      return V{};
    }

    auto p = pointer_[key];
    K k = p->key;
    V v = p->value;
    update(k, v);
    return v;
  }

  void put(K key, V value) {
    if (capacity_ == 0) {
      return;
    }

    if (pointer_.count(key)) {
      update(key, value);
    } else {
      if ((int)pointer_.size() >= capacity_) {
        auto first = use_count_.begin();
        auto to_remove = first->second.begin();

        pointer_.erase(to_remove->key);
        first->second.erase(to_remove);
        if (first->second.size() == 0) {
          use_count_.erase(first->first);
        }
      }

      use_count_[1].emplace_back(key, value, 1);
      auto p = prev(use_count_[1].end());
      pointer_[key] = p;
    }
  }

  void update(K key, V value) {
    auto p = pointer_[key];
    int use_count = p->use_count;
    use_count_[use_count].erase(p);
    if (use_count_[use_count].size() == 0) {
      use_count_.erase(use_count);
    }
    pointer_.erase(key);

    use_count_[use_count + 1].emplace_back(key, value, use_count + 1);
    auto p2 = prev(use_count_[use_count + 1].end());
    pointer_[key] = p2;
  }

 private:
  using Item = DataItem<K, V>;

  int capacity_;
  std::unordered_map<K, typename std::list<Item>::iterator> pointer_;
  std::map<int, std::list<Item>> use_count_;
};

// Define the Python module
PYBIND11_MODULE(module, m) {
  m.doc() = "pybind11 example module";

  m.def("get_memory_info", &get_memory_info, "get system memory info");

  using LFU = LFUCache<std::string, std::string>;
  namespace py = pybind11;
  py::class_<LFU>(m, "LFU")
      .def(py::init<int>())
      .def("get", &LFU::get)
      .def("put", &LFU::put)
      .def("update", &LFU::update);
}
