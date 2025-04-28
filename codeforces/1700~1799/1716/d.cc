#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> dp(n+1);
  vector<i64> dp2(n+1);
  dp[0] = 1;
  vector<i64> ans(n+1);
  constexpr int MOD = 998244353;
  for (int step = k, total = k, start = 1; total <= n; ++step, total += step, start += step) {
    fill(dp2.begin()+start, dp2.end(), 0);
    for (int i = start; i <= n; ++i) {
      if (i-step >= 0) {
        dp[i] += dp[i-step];
        dp[i] %= MOD;
      }
    }
    for (int i = start; i <= n; ++i) {
      if (i-step >= 0) {
        dp2[i] += dp[i-step];
        dp2[i] %= MOD;
      }
    }
    for (int i = start; i <= n; ++i) {
      dp[i] = dp2[i];
    }
    // dp = std::move(dp2);
    // for (int i = 1; i <= n; ++i) {
    //   cout << dp[i] << " ";
    // }
    // cout << endl;
    for (int i = start; i <= n; ++i) {
      ans[i] += dp[i];
      ans[i] %= MOD;
    }
  }

  for (int i = 1; i <= n ; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
