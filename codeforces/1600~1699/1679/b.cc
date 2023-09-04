#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(vector<i64>& arr) : data_(4 * arr.size()), lazy_(4 * arr.size()) {
    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l == r) {
        data_[i] = arr[l];
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

    int n = arr.size();
    build(0, 0, n-1);
  }

  void update(int i, int tl, int tr, int ul, int ur, i64 x) {
    push(i, tl, tr);
    if (tr < ul || tl > ur) {
      return;
    }
    if (tl >= ul && tr <= ur) {
      data_[i] = (tr - tl + 1) * x;
      if (tl != tr) {
        lazy_[i*2+1] = lazy_[i*2+2] = x;
      }
      lazy_[i] = 0;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    update(i*2+1, tl, tm, ul, ur, x);
    update(i*2+2, tm+1, tr, ul, ur, x);
    data_[i] = data_[i*2+1] + data_[i*2+2];
  }

  i64 query(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);
    if (tr < ql || tl > qr) {
      return 0;
    }
    
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = tl + (tr - tl) / 2;
    return query(i*2+1, tl, tm, ql, min(qr, tm)) +
      query(i*2+2, tm+1, qr, max(ql, tm+1), qr);
  }

 private:
  vector<i64> data_;
  vector<i64> lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      data_[i] = (tr - tl + 1) * lazy_[i];
      if (tl != tr) {
        lazy_[i*2+1] = lazy_[i*2+2] = lazy_[i];
      }
      lazy_[i] = 0;
    }
  }
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  SegmentTree tree(a);

  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int index = 0;
      i64 x = 0;
      cin >> index >> x;
      index--;
      tree.update(0, 0, n-1, index, index, x);
    } else if (type == 2) {
      i64 x = 0;
      cin >> x;
      tree.update(0, 0, n-1, 0, n-1, x);
    }

    i64 ans = tree.query(0, 0, n-1, 0, n-1);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
