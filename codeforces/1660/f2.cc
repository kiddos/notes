#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

  void update(int i, int x) {
    int n = data_.size();
    while (i < n) {
      data_[i] += x;
      i += (i & -i);
    }
  }

  int get(int i) {
    int x = 0;
    while (i > 0) {
      x += data_[i];
      i -= (i & -i);
    }
    return x;
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int offset = n+1;
  int size = 2 * offset;
  FenwickTree trees[3] = {
    FenwickTree(size),
    FenwickTree(size),
    FenwickTree(size),
  };
  trees[0].update(offset, 1);

  int diff = 0;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      diff--;
    } else if (s[i] == '-') {
      diff++;
    }

    int m = ((diff % 3) + 3) % 3;
    // cout << "m=" << m << endl;
    FenwickTree& tree = trees[m];
    ans += tree.get(diff + offset);
    // cout << "ans=" << ans << endl;
    tree.update(diff + offset, 1);
  }
  cout << ans << endl;
}

// +++---
// 0. 0: 1
// 1. 0: 1, -1: 1
// 2: 0: 1, -1: 1, -2: 1
// 3: 0: 2, -1: 1, -2: 1
// 4: 0: 2, -1: 2, -2: 1

// promising:
// --- -> +-
// +----
// +------- -> +++---
// diff of 0, 3, 6, 9, ...

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
