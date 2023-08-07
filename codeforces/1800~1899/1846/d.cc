#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  double d = 0, h = 0;
  cin >> n >> d >> h;
  vector<ll> y(n);
  for (int i = 0; i < n; ++i) cin >> y[i];

  double ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += d * h / 2.0;
    if (i > 0) {
      if (y[i] < y[i-1] + h) {
        double h2 = y[i-1] + h - y[i];
        double d2 = d * h2 / h;
        ans -= d2 * h2 / 2.0;
      }
    }
  }

  printf("%.6f\n", ans);
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
