#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<vector<i64>> dp(n+1, vector<i64>(k+1));
  for (int j = 1; j <= k; ++j) {
    dp[0][j] = 1;
  }

  constexpr int MOD = 998244353;
  for (int sum = 1; sum <= n; ++sum) {
    for (int last = 1; last <= k; ++last) {
      int to = min(sum / last, k - last + 1);
      for (int p = 1; p <= to; ++p) {
        dp[sum][last] += dp[sum - last * p][p];
        dp[sum][last] %= MOD;
      }
    }
  }

  i64 ans = 0;
  for (int j = 0; j <= k; ++j) {
    ans += dp[n][j];
    ans %= MOD;
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
