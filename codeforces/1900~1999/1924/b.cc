#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n, vector<i64>& values, vector<i64>& dist) : data_(4*(n+1), {0, 0, 0}), lazy_(4*(n+1), {0, 0}) {
    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l == r) {
        data_[i][0] = values[l];
        data_[i][1] = dist[l];
        data_[i][2] = data_[i][0] * data_[i][1];
        return;
      }
      if (l > r) {
        return;
      }

      int m = l + (r-l) / 2;
      build(i*2+1, l, m);
      build(i*2+2, m+1, r);

      if (data_[i*2+1][0] == data_[i*2+2][0]) {
        data_[i][0] = data_[i*2+1][0];
      }
      data_[i][1] = data_[i*2+1][1] + data_[i*2+2][1];
      data_[i][2] = data_[i*2+1][2] + data_[i*2+2][2];
    };

    build(0, 0, n);
  }

  void update(int i, int tl, int tr, int l, int r, i64 value, i64 dist) {
    if (tr < l || tl > r) {
      return;
    }

    push(i, tl, tr);
    if (tl >= l && tr <= r) {
      i64 len = tr - tl + 1;
      data_[i][0] += value;
      data_[i][1] += len * dist;
      data_[i][2] = data_[i][0] * data_[i][1];

      if (tl != tr) {
        lazy_[i*2+1][0] += value;
        lazy_[i*2+1][1] += dist;

        lazy_[i*2+2][0] += value;
        lazy_[i*2+2][1] += dist;
      }
      return;
    }

    int tm = tl + (tr-tl) / 2;
    if (l <= tm) update(i*2+1, tl, tm, l, r, value, dist);
    if (r > tm) update(i*2+2, tm+1, tr, l, r, value, dist);

    data_[i][0] = value;
    data_[i][1] = data_[i*2+1][1] + data_[i*2+2][1];
    data_[i][2] = data_[i*2+1][2] + data_[i*2+2][2];
  }

  i64 query(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) {
      return 0;
    }

    push(i, tl, tr);
    if (tl >= ql && tr <= qr) {
      return data_[i][2];
    }

    int tm = tl + (tr - tl) / 2;
    i64 left = query(i*2+1, tl, tm, ql, min(qr, tm));
    i64 right = query(i*2+2, tm+1, tr, max(ql, tm+1), qr);
    i64 sum = left + right;
    return sum;
  }

 private:
  vector<array<i64,3>> data_;
  vector<array<i64,2>> lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i][0] || lazy_[i][1]) {
      int len = tr - tl + 1;
      data_[i][0] += lazy_[i][0];
      data_[i][1] += len * lazy_[i][1];
      data_[i][2] = data_[i][0] * data_[i][1];

      if (tl != tr) {
        lazy_[i*2+1][0] += lazy_[i][0];
        lazy_[i*2+1][1] += lazy_[i][1];

        lazy_[i*2+2][0] += lazy_[i][0];
        lazy_[i*2+2][1] += lazy_[i][1];
      }
    
      lazy_[i][0] = lazy_[i][1] = 0;
    }
  }
};

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<int> x(m);
  for (int i = 0; i < m; ++i) cin >> x[i];
  vector<i64> v(m);
  for (int i = 0; i < m; ++i) cin >> v[i];

  map<int,i64> values;
  for (int i = 0; i < m; ++i) {
    values[x[i]] = v[i];
  }

  vector<i64> dist(n+1);
  vector<i64> vals(n+1);

  for (int pos = 1; pos <= n; ++pos) {
    auto right = values.lower_bound(pos);
    dist[pos] = right->first - pos;
    auto left = values.upper_bound(pos-1);
    if (left != values.begin()) {
      left--;
      vals[pos] = left->second;
    }
  }

  SegmentTree tree(n, vals, dist);
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int xi = 0;
      i64 vi = 0;
      cin >> xi >> vi;

      auto right = values.lower_bound(xi);
      auto left = --values.upper_bound(xi);
      i64 v = vi - left->second;
      tree.update(0, 0, n, xi+1, right->first, v, 0);
      i64 dist = right->first - xi;
      tree.update(0, 0, n, left->first+1, xi, 0, -dist);

      values[xi] = vi;
    } else if (t == 2) {
      int l = 0, r = 0;
      cin >> l >> r;

      i64 ans = tree.query(0, 0, n, l, r);
      cout << ans << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
