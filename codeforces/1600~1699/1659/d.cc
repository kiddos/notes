#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 0 3 4 2 3 2 7
// Bn = 0 0 0 0 1 1 1
// -> 0 3 4 2 2 1 6
// -> 0 3 4 2 1 0 5
// -> 0 3 4 1 0 0 4
// -> 0 3 3 0 0 0 3

class SegmentTree {
 public:
  SegmentTree(vector<int>& c) : data_(c.size() * 4), lazy_(c.size() * 4) {
    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l == r) {
        data_[i] = c[l];
        return;
      }
      if (l > r) {
        return;
      }

      int m = l + (r-l) / 2;
      build(i*2+1, l, m);
      build(i*2+2, m+1, r);
      data_[i] = data_[i*2+1] + data_[i*2+2];
    };

    build(0, 0, c.size()-1);
  }

  void update(int i, int tl, int tr, int l, int r, int x) {
    if (tl > r || tr < l) {
      return;
    }

    push(i, tl, tr);
    if (tl >= l && tr <= r) {
      data_[i] += (tr - tl + 1) * x;
      if (tl != tr) {
        lazy_[i*2+1] += x;
        lazy_[i*2+2] += x;
      }
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (l <= tm) update(i*2+1, tl, tm, l, r, x);
    if (r > tm) update(i*2+2, tm+1, tr, l, r, x);
    data_[i] = data_[i*2+1] + data_[i*2+2];
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) {
      return 0;
    }

    push(i, tl, tr);
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = tl + (tr - tl) / 2;
    return query(i*2+1, tl, tm, ql, min(qr, tm)) +
      query(i*2+2, tm+1, tr, max(ql, tm+1), qr);
  }

 private:
  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      data_[i] += (tr - tl + 1) * lazy_[i];
      if (tl != tr) {
        lazy_[i*2+1] += lazy_[i];
        lazy_[i*2+2] += lazy_[i];
      }
      lazy_[i] = 0;
    }
  }

  vector<int> data_, lazy_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  i64 total = accumulate(c.begin(), c.end(), 0LL);
  i64 ones = total / n;

  SegmentTree tree(c);

  vector<int> ans(n);
  if (ones > 0) {
    for (int i = n-1; i >= 0; --i) {
      int from = i-ones+1, to = i;
      if (tree.query(0, 0, n-1, i, i) == i+1) {
        ans[i] = 1;
        ones--;
      }
      if (ones > 0) {
        tree.update(0, 0, n-1, from, to, -1);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
