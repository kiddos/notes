#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
 public:
  SegmentTree(vector<int>& data) {
    int n = data.size();
    int x = ceil(log2(n)) + 1;
    int size = pow(2, x) -1;

    max_vals_ = vector<int>(size);
    min_vals_ = vector<int>(size);

    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l > r) return;
      if (l == r) {
        max_vals_[i] = data[l];
        min_vals_[i] = data[l];
        return;
      }

      int m = l + (r-l) / 2;
      build(i * 2 + 1, l, m);
      build(i * 2 + 2, m+1, r);

      max_vals_[i] = max(max_vals_[i*2+1], max_vals_[i*2+2]);
      min_vals_[i] = min(min_vals_[i*2+1], min_vals_[i*2+2]);
    };
    build(0, 0, n-1);
  }

  pair<int,int> query(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return {max_vals_[i], min_vals_[i]};
    }
    if (tl > qr || tr < ql) {
      return {numeric_limits<int>::min(), numeric_limits<int>::max()};
    }

    int tm = tl + (tr-tl) / 2;
    auto left = query(i * 2 + 1, tl, tm, ql, min(qr, tm));
    auto right = query(i * 2 + 2, tm+1, tr, max(ql, tm+1), qr);
    return {max(left.first, right.first), min(left.second, right.second)};
  }

 private:
  vector<int> max_vals_, min_vals_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  SegmentTree tree(a);
  int l = 0, r = n-1;
  while (l < r) {
    auto vals = tree.query(0, 0, n-1, l, r);

    if (a[l] != vals.first && a[l] != vals.second &&
        a[r] != vals.first && a[r] != vals.second) {
      // cout << vals.first << ", " << vals.second << endl;
      cout << l+1 << " " << r+1 << endl;
      return;
    }

    if (a[l] == vals.first || a[l] == vals.second) {
      l++;
    }
    if (a[r] == vals.first || a[r] == vals.second) {
      r--;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
