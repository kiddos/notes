#include <bits/stdc++.h>

using namespace std;

// Iterator for Combination
//
// bit mask solution seems more general

class CombinationIterator {
 public:
  CombinationIterator(string characters, int combinationLength) : index_(0) {
    int n = characters.length();
    int m = 1 << n;
    for (int mask = 0; mask < m; ++mask) {
      if (__builtin_popcount(mask) != combinationLength) continue;
      string s;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          s.push_back(characters[i]);
        }
      }
      data_.push_back(s);
    }

    sort(data_.begin(), data_.end());

    // function<void(int, string&)> generate = [&](int index, string& current) {
    //   if (index == n) {
    //     if (current.length() == combinationLength) {
    //       data_.push_back(current);
    //     }
    //     return;
    //   }

    //   current.push_back(characters[index]);
    //   generate(index + 1, current);
    //   current.pop_back();
    //   generate(index + 1, current);
    // };
    // string current;
    // generate(0, current);
  }

  string next() { return data_[index_++]; }

  bool hasNext() { return index_ < data_.size(); }

 private:
  int index_;
  vector<string> data_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  auto it = CombinationIterator("abcde", 3);
  while (it.hasNext()) {
    cout << it.next() << endl;
  }

  return 0;
}
