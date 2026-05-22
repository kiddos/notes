#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int msb(int x) {
  return 31 - __builtin_clz(x);
}

class SegmentTree {
 public:
  SegmentTree(int n) : n(n), data_(n * 4) {}

  SegmentTree(vector<int>& data) : n(data.size()), data_(data.size() * 4) {
    build_tree(data, 0, 0, n - 1);
  }

  void build_tree(vector<int>& data, int i, int tl, int tr) noexcept {
    if (tl == tr) {
      data_[i] = data[tl];
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build_tree(data, i * 2 + 1, tl, tm);
    build_tree(data, i * 2 + 2, tm + 1, tr);
    int len = tr - tl + 1;
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2], len);
  }

  int query(int i, int tl, int tr, int ql, int qr) noexcept {
    if (tr < ql || tl > qr) {
      return 0;
    }
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = (tl + tr) / 2;
    int left = query(i * 2 + 1, tl, tm, ql, qr);
    int right = query(i * 2 + 2, tm + 1, tr, ql, qr);
    int len = tr - tl + 1;
    return merge(left, right, len);
  }

  int query(int ql, int qr) noexcept { return query(0, 0, n - 1, ql, qr); }

  void update(int i, int tl, int tr, int index, const int& val) noexcept {
    if (tl == tr) {
      data_[i] = val;
      return;
    }

    int tm = (tl + tr) / 2;
    if (index <= tm) {
      update(i * 2 + 1, tl, tm, index, val);
    } else {
      update(i * 2 + 2, tm + 1, tr, index, val);
    }
    int len = tr - tl + 1;
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2], len);
  }

  void update(int index, const int& val) noexcept { update(0, 0, n - 1, index, val); }

 private:
  int n;
  vector<int> data_;

  inline int merge(int x, int y, int len) {
    int m1 = msb(len);
    if (m1 % 2 == 1) {
      return x | y;
    } else {
      return x ^ y;
    }
  }
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int size = 1 << n;
  vector<int> a(size);
  for (int i = 0; i < size; ++i) {
    cin >> a[i];
  }

  SegmentTree tree(a);

  vector<int> p(m), b(m);
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    cin >> p[i] >> b[i];
    p[i]--;
    tree.update(p[i], b[i]);
    ans.push_back(tree.query(0, size-1));
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
