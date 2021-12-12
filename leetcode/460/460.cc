#include <bits/stdc++.h>

using namespace std;

// LFU Cache
//
// The idea is very similar to Least Recently Used cache
// but instead of just having 1 linked list, we have multiple linkedlist
// group by the nodes used frequency
//
// so we have
// unordered_map<int, list<Node>> freq_;
// unordered_map<int, list<Node>::iterator> nodes_;
//
// get:
// remove the node (eg. nodes_[key]) from freq_
// and increment the freq
// and insert the node to freq+1
//
// put:
// if nodes_ already has the key
//   do very similar thing with get
//   but also change the value
// else
//   when the capacity is at max
//   remove the freq_[min_freq_]'s last node
//   
//   insert the node at freq == 1

struct Node {
  int key;
  int value;
  int freq;
};

class LFUCache {
 public:
  LFUCache(int capacity) : capacity_(capacity), min_freq_(0) {}

  int get(int key) {
    if (!nodes_.count(key)) return -1;

    auto p = nodes_[key];
    Node node = *p;
    freq_[node.freq].erase(p);
    if (node.freq == min_freq_ && freq_[node.freq].size() == 0) {
      min_freq_++;
    }

    node.freq++;
    freq_[node.freq].push_front(node);
    nodes_[key] = freq_[node.freq].begin();
    return node.value;
  }

  void put(int key, int value) {
    if (capacity_ == 0) return;

    if (nodes_.count(key)) {
      auto p = nodes_[key];
      Node node = *p;
      freq_[node.freq].erase(p);
      if (node.freq == min_freq_ && freq_[node.freq].size() == 0) {
        min_freq_++;
      }

      node.freq++;
      node.value = value;
      freq_[node.freq].push_front(node);
      nodes_[key] = freq_[node.freq].begin();
    } else {
      if (nodes_.size() == capacity_) {
        Node to_remove = freq_[min_freq_].back();
        freq_[min_freq_].pop_back();
        nodes_.erase(to_remove.key);
      }

      Node new_node{key, value, 1};
      freq_[1].push_front(new_node);
      nodes_[key] = freq_[1].begin();
      min_freq_ = 1;
    }
  }

 private:
  int capacity_;
  int min_freq_;
  unordered_map<int, list<Node>> freq_;
  unordered_map<int, list<Node>::iterator> nodes_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  LFUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  assert(cache.get(1) == 1);

  cache.put(3, 3);
  assert(cache.get(2) == -1);
  assert(cache.get(3) == 3);

  cache.put(4, 4);
  assert(cache.get(1) == -1);
  assert(cache.get(3) == 3);
  assert(cache.get(4) == 4);
  return 0;
}
