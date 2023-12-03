#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(vector<int>& a) : data_(a.size() * 4) {
    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l == r) {
        data_[i] = a[l];
        return;
      }
      if (l > r) {
        return;
      }

      int m = l + (r-l) / 2;
      build(i*2, l, m);
      build(i*2+1, m+1, r);
      data_[i] = data_[i*2] & data_[i*2+1];
    };

    int n = a.size() - 1;
    build(1, 1, n);
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }
    if (tl > qr || tr < ql) {
      return ~0;
    }
    int tm = tl + (tr - tl) / 2;
    return query(i*2, tl, tm, ql, min(qr, tm)) & query(i*2+1, tm+1, tr, max(ql, tm+1), qr);
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  SegmentTree tree(a);

  int q = 0;
  cin >> q;
  while (q-- > 0) {
    int l = 0, k = 0;
    cin >> l >> k;
    int r = n;
    int l0 = l;
    int ans = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int ands = tree.query(1, 1, n, l0, mid);
      if (ands >= k) {
        l = mid+1;
        ans = mid;
      } else {
        r = mid-1;
      }
    }

    cout << ans << " ";
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
