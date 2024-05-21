#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int m = 0, x = 0;
  cin >> m >> x;
  vector<i64> c(m), h(m);
  for (int i = 0; i < m; ++i) {
    cin >> c[i] >> h[i];
  }

  int h_sum = accumulate(h.begin(), h.end(), 0);

  vector<i64> dp(h_sum+1, -1);
  dp[0] = 0;
  for (int i = 0; i < m; ++i) {
    vector<i64> next_dp = dp;
    for (int j = 0; j <= h_sum; ++j) {
      if (dp[j] >= 0 && dp[j] - c[i] >= 0) {
        next_dp[j + h[i]] = max(next_dp[j + h[i]], dp[j] - c[i]);
      }
    }
    for (int j = 0; j <= h_sum; ++j) {
      if (next_dp[j] >= 0) {
        next_dp[j] += x;
      }
    }
    dp = std::move(next_dp);
    // for (int j = 0; j <= MAX_H; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << endl;
  }
  int ans = 0;
  for (int j = 0; j <= h_sum; ++j) {
    if (dp[j] >= 0) {
      ans = max(ans, j);
    }
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
