#include <bits/stdc++.h>

using namespace std;

// Least Recent used cache
// get needs to
// 1. if key not found return -1
// 2. if found move the list node to front and return
//
// put needs to
// 1. if key found, update the value and move the list node to front, and return
// 2. if cache size >= capacity, remove the last element in cache
// 3. push the new element

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (!map_.count(key)) return -1;
    auto p = map_[key];
    cache_.splice(cache_.begin(), cache_, p);
    return p->second;
  }

  void put(int key, int value) {
    if (map_.count(key)) {
      auto p = map_[key];
      cache_.splice(cache_.begin(), cache_, p);
      p->second = value;
      return;
    }

    if (cache_.size() >= capacity_) {
      auto p = cache_.back();
      map_.erase(p.first);
      cache_.pop_back();
    }

    cache_.push_front({key, value});
    map_[key] = cache_.begin();
  }

 private:
  int capacity_;
  list<pair<int, int>> cache_;
  unordered_map<int, list<pair<int, int>>::iterator> map_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  assert(cache.get(1) == 1);
  cache.put(3, 3);
  assert(cache.get(2) == -1);
  cache.put(4, 4);
  assert(cache.get(1) == -1);
  assert(cache.get(3) == 3);
  assert(cache.get(4) == 4);
  return 0;
}
