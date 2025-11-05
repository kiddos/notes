#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : sums_(n+1) {}

  void update(int i, i64 delta) {
    int n = sums_.size();
    while (i < n) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  i64 query(int i) {
    i64 sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  inline int lowbit(int x) { return x & (-x); }

  vector<i64> sums_;
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> x(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  FenwickTree tree(n+2);
  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int a = 0, b = 0, u = 0;
      cin >> a >> b >> u;
      tree.update(a, u);
      tree.update(b+1, -u);
    } else if (type == 2) {
      int k = 0;
      cin >> k;
      i64 result = x[k] + tree.query(k);
      ans.push_back(result);
    }
  }

  for (i64 val : ans) {
    cout << val << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
