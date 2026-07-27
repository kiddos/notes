#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(const vector<int>& a) : a_(a), data_(a.size() * 4) {
    auto build = [&](const auto& self, int i, int tl, int tr) -> void {
      if (tl > tr) {
        return;
      }
      if (tl == tr) {
        data_[i] = a[tl];
        return;
      }
      int tm = tl + (tr - tl) / 2;
      self(self, i * 2 + 1, tl, tm);
      self(self, i * 2 + 2, tm + 1, tr);
      data_[i] = data_[i * 2 + 1] & data_[i * 2 + 2];
    };

    int n = a.size();
    build(build, 0, 0, n-1);
  }

  int query_and(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) {
      return ~0;
    }
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }
    int tm = tl + (tr-tl) / 2;
    int left = query_and(i * 2 + 1, tl, tm, ql, qr);
    int right = query_and(i * 2 + 2, tm + 1, tr, ql, qr);
    return left & right;
  }

  int query_and(int ql, int qr) {
    int n = a_.size();
    return query_and(0, 0, n-1, ql, qr);
  }

 private:
  vector<int> a_;
  vector<int> data_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> l(m), r(m), k(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> k[i];
    l[i]--;
    r[i]--;
  }

  vector<vector<int>> bits(n+1, vector<int>(30));
  for (int i = 0; i < m; ++i) {
    for (int b = 0; b < 30; ++b) {
      if (k[i] & (1<<b)) {
        bits[l[i]][b]++;
        bits[r[i]+1][b]--;
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int b = 0; b < 30; ++b) {
      bits[i][b] += bits[i-1][b];
    }
  }

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int b = 0; b < 30; ++b) {
      if (bits[i][b] > 0) {
        x |= (1<<b);
      }
    }
    arr[i] = x;
  }

  SegmentTree tree(arr);
  for (int i = 0; i < m; ++i) {
    int result = tree.query_and(l[i], r[i]);
    if (result != k[i]) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (int i= 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
