#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : n(n), data_(n * 4) {}

  void update(int i, int tl, int tr, int idx, int x) {
    if (tl == tr) {
      data_[i] = x;
      return;
    }
    if (tl > tr) {
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (idx <= tm) {
      update(i * 2 + 1, tl, tm, idx, x);
    } else {
      update(i * 2 + 2, tm + 1, tr, idx, x);
    }
    data_[i] = min(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  void update(int idx, int x) {
    update(0, 0, n-1, idx, x);
  }

  int query_min(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    if (tl > qr || tr < ql) {
      return numeric_limits<int>::max();
    }

    int tm = tl + (tr - tl) / 2;
    int left = query_min(i * 2 + 1, tl, tm, ql, qr);
    int right = query_min(i * 2 + 2, tm + 1, tr, ql, qr);
    return min(left, right);
  }

  int query_min(int l, int r) {
    return query_min(0, 0, n-1, l, r);
  }

 private:
  int n;
  vector<i64> data_;
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  SegmentTree tree(n);
  for (int i = 0; i < n; ++i) {
    tree.update(i, x[i]);
  }

  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int k = 0, u = 0;
      cin >> k >> u;
      k--;
      tree.update(k, u);
      x[i] = u;
    } else if (type == 2) {
      int a = 0, b = 0;
      cin >> a >> b;
      a--;
      b--;
      i64 result = tree.query_min(a, b);
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
