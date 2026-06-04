#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 s = 0;
  cin >> n >> s;
  vector<int> x(n), y(n), k(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> k[i];
  }
  double max_x = *max_element(x.begin(), x.end());
  double max_y = *max_element(y.begin(), y.end());
  double l = 0, r = sqrt(max_x * max_x + max_y * max_y) + 1;
  double ans = -1;
  while ((r - l) >= 1e-6) {
    double mid = (l + r) / 2.0;
    i64 total = s;
    for (int i = 0; i < n; ++i) {
      double r2 = mid * mid;
      if (x[i] * x[i] + y[i] * y[i] <= r2) {
        total += k[i];
      }
    }
    if (total >= 1000000) {
      r = mid;
      ans = mid;
    } else {
      l = mid;
    }
  }
  if (ans < 0) {
    cout << "-1" << endl;
  } else {
    cout << fixed << setprecision(8) << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
