#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  double p = 0;
  int t = 0;
  cin >> n >> p >> t;

  vector<double> dp(n+1);
  dp[0] = 1.0;

  for (int i = 1; i <= t; ++i) {
    vector<double> dp2 = dp;
    for (int j = n-1; j >= 0; --j) {
      dp2[j+1] += dp[j] * p;
      dp2[j] *= (1.0-p);
    }
    dp = std::move(dp2);

    // cout << endl;
    // for (int j = 0; j <= n; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << endl;
  }

  double ans = 0;
  for (int k = 1; k <= n; ++k) {
    ans += dp[k] * k;
  }
  cout << fixed << setprecision(9) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
