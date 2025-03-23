#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<vector<i64>> dp(k+1, vector<i64>(n+1, 1));
  constexpr int MOD = 1e9 + 7;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i][j-1];
      if (i > 1) {
        dp[i][j] += dp[i-1][n-j];
        dp[i][j] %= MOD;
      }
    }
  }
  i64 ans = dp[k][n];
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
