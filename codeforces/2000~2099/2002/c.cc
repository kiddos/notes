#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  i64 xs = 0, ys = 0, xt = 0, yt = 0;
  cin >> xs >> ys >> xt >> yt;

  auto dist = [&](i64 x1, i64 y1, i64 x2, i64 y2) -> i64 {
    i64 dx = x1 - x2;
    i64 dy = y1 - y2;
    return dx * dx + dy * dy;
  };
  
  i64 d0 = dist(xs, ys, xt, yt);
  for (int i = 0; i < n; ++i) {
    i64 d1 = dist(xt, yt, x[i], y[i]);
    if (d1 <= d0) {
      // cout << i << endl;
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
