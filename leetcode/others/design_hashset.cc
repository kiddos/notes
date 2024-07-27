#include <bits/stdc++.h>

using namespace std;

class HashSet {
 public:
  HashSet(int capacity) : size_(0), data_(capacity) {}

  int get_index(int key) {
    return hash<int>{}(key) % data_.size();
  }

  void add(int key) {
    if (contains(key)) return;

    if (data_.size() * 0.7 == size_) {
      size_ = 0;
      int new_capacity = data_.size() * 2;
      vector<list<int>> old_data = std::move(data_);
      data_ = vector<list<int>>(new_capacity);
      for (list<int> bucket : old_data) {
        for (int k : bucket) {
          add(k);
        }
      }
    }


    data_[get_index(key)].push_back(key);
    size_++;
  }

  void remove(int key) {
    list<int>& bucket = data_[get_index(key)];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
      if ((*it) == key) {
        bucket.erase(it);
        size_--;
        break;
      }
    }
  }

  bool contains(int key) {
    list<int>& bucket = data_[get_index(key)];
    for (int k : bucket) {
      if (k == key) return true;
    }

    return false;
  }

 private:
  int size_;
  vector<list<int>> data_;
};

int main(void) {
  int n = 10000;
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(0, 1000000);

  HashSet set(100);
  for (int i = 0; i < n; ++i) {
    set.add(i);
    assert(set.contains(i));
  }

  for (int i = 0; i < n; ++i) {
    set.remove(i);
    assert(!set.contains(i));
  }
  return 0;
}
