#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
 public:
  FenwickTree(int n) : sums_(n+1) {}

  void update(int i, int delta) {
    int n = sums_.size();
    while (i < n) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  inline int lowbit(int x) { return x & (-x); }

  vector<int> sums_;
};

int main(void) {
  // code here...
  return 0;
}
