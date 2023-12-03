#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : n(n), count_(n * 4) {}

  void update(int i, int tl, int tr, int index, int x) {
    if (tl == tr) {
      count_[i] += x;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (index <= tm) {
      update(i*2+1, tl, tm, index, x);
    } else {
      update(i*2+2, tm+1, tr, index, x);
    }
    count_[i] = count_[i*2+1] + count_[i*2+2];
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return count_[i];
    }
    if (tl > qr || tr < ql) {
      return 0;
    }

    int tm = tl + (tr - tl) / 2;
    return query(i*2+1, tl, tm, ql, min(qr, tm)) +
      query(i*2+2, tm+1, tr, max(ql, tm+1), qr);
  }

  int mex() {
    int l = 0, r = n-1;
    int ans = 0;
    while (l <= r) {
      int m = l + (r-l) / 2;
      int count = query(0, 0, n-1, 0, m);
      if (count < m+1) {
        ans = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }
    return ans;
  }

 private:
  int n;
  vector<int> count_;
};

void alice(int x) {
  cout << x << endl;
}

int bob() {
  int y = 0;
  cin >> y; 
  return y;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  int m = n * 2;
  SegmentTree tree(m);
  for (int i = 0; i < n; ++i) {
    if (s[i] < m) {
      tree.update(0, 0, m-1, s[i], 1);
    }
  }

  while (true) {
    int mex = tree.mex();
    alice(mex);
    tree.update(0, 0, m-1, mex, 1);
    int y = bob();
    if (y < 0) {
      break;
    }
    tree.update(0, 0, m-1, y, -1);
  }
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
