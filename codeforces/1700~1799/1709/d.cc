#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class SegmentTree {
 public:
  SegmentTree(vector<ll>& a) : max_vals_(a.size() * 4) {
    function<void(int,int,int)> build = [&](int i, int tl, int tr) {
      if (tl > tr) return;

      if (tl == tr) {
        max_vals_[i] = a[tl];
        return;
      }

      int tm = tl + (tr - tl) / 2;
      build(i*2+1, tl, tm);
      build(i*2+2, tm+1, tr);
      max_vals_[i] = max(max_vals_[i*2+1], max_vals_[i*2+2]);
    };

    int n = a.size();
    build(0, 0, n-1);
  }

  ll query(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) return 0;
    if (tl >= ql && tr <= qr) {
      return max_vals_[i];
    }

    int tm = tl + (tr - tl) / 2;
    return max(
      query(i*2+1, tl, tm, ql, min(qr, tm)),
      query(i*2+2, tm+1, tr, max(ql, tm+1), qr)
    );
  }

 private:
  vector<ll> max_vals_;
};

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;

  vector<ll> a(m+1);
  for (int i = 1; i <= m; ++i) cin >> a[i];

  SegmentTree tree(a);

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll xs = 0, ys = 0, xf = 0, yf = 0, k = 0;
    cin >> xs >> ys >> xf >> yf >> k;

    ll dx = xf - xs;
    ll dy = yf - ys;
    if (dx % k != 0 || dy % k != 0) {
      cout << "NO" << endl;
      continue;
    }

    ll max_height = tree.query(0, 0, a.size()-1, min(ys, yf), max(ys, yf));
    if (max_height >= max(xs, xf)) {
      if (max_height >= n) {
        cout << "NO" << endl;
        continue;
      }
      ll diff = max_height+1 - min(xs, xf);
      ll up_command = (diff + k - 1) / k;
      if (min(xs, xf) + up_command * k > n) {
        cout << "NO" << endl;
        continue;
      }
    }

    cout << "YES" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
