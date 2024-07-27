#include <bits/stdc++.h>

using namespace std;

class HashMap {
 public:
  HashMap() : size_(0), data_(100) {
  }

  void put(int key, int value) {
    if (data_.size() * 0.7 < size_) {
      size_ = 0;
      int new_capacity = data_.size() * 2;
      auto old_data = std::move(data_);
      data_ = vector<list<pair<int, int>>>(new_capacity);
      for (auto& bucket: old_data) {
        for (auto& p : bucket) {
          put(p.first, p.second);
        }
      }
    }

    auto& bucket = data_[bucket_index(key)];
    for (auto& p : bucket) {
      if (p.first == key) {
        p.second = value;
        return;
      }
    }
    bucket.push_front({key, value});
    size_++;
  }

  int get(int key) {
    auto& bucket = data_[bucket_index(key)];
    for (auto& p : bucket) {
      if (p.first == key) return p.second;
    }
    return -1;
  }

  void remove(int key) {
    auto& bucket = data_[bucket_index(key)];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
      if (it->first == key) {
        bucket.erase(it);
        break;
      }
    }
  }

 private:
  int size_;
  vector<list<pair<int, int>>> data_;

  int bucket_index(int key) {
    return std::hash<int>{}(key) % data_.size();
  }
};

int main(void) {
  int n = 100000;
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(0, n*2);

  HashMap map;
  for (int i = 0; i < n; ++i) {
    map.put(i, i+1);
    assert(map.get(i) == i+1);
  }

  for (int i = 0; i < n; ++i) {
    map.remove(i);
    assert(map.get(i) == -1);
  }

  return 0;
}
