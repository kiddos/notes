#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  vector<int> ans;
  FenwickTree tree(n+1);
  for (int i = 1; i <= n; ++i) {
    tree.update(i, 1);
  }

  for (int i = 0; i < n; ++i) {
    int p = 0;
    cin >> p;
    int l = 1, r = n;
    int idx = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int prefix_count = tree.query(mid);
      if (prefix_count >= p) {
        idx = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    tree.update(idx, -1);
    ans.push_back(x[idx]);
  }

  for (int val : ans) {
    cout << val << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
