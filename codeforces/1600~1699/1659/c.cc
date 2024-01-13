#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// conquer from 0
// b * (x0 - 0) + b * (x1 - 0) + b * (x2 - 0) + ... + b * (xn-1 - 0)
// conquer from x0
// b * (x0 - 0) + a * (x0 - 0) + b * (x1 - x0) + b * (x2 - x0) + ... + b * (xn-1 - x0)
// conquer from x1
// b * (x0 - 0) + a * (x0 - 0) + b * (x1 - x0) + a * (x1 - x0) + b * (x2 - x1) + ... + b * (xn-1 - x1)

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  i64 c0 = 0;
  for (int i = 0; i < n; ++i) {
    c0 += b * x[i];
  }

  i64 ans = c0;
  i64 remove = 0;
  i64 add = 0;
  i64 last = 0;
  //cout << "cost = " << c0 << endl;
  for (int i = 0; i < n; ++i) {
    remove += b * x[i];
    if (i == n-1) {
      add += b * (x[i] - last);
    } else {
      add += b * (x[i] - last) + a * (x[i] - last);
    }
    last = x[i];

    i64 cost = c0 - remove + add - b * x[i] * (n-i-1);
    //cout << "cost = " << cost << endl;
    ans = min(ans, cost);
  }

  cout << ans << endl;
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
