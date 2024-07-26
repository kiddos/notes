#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  constexpr int MOD = 998244353;

  // split array of size n in to at least k blocks
  vector<vector<i64>> dp(n+1, vector<i64>(k+1));
  vector<i64> p(k+1);
  dp[0][0] = 1;
  p[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      i64& d = dp[i+1][min(j+1, k)];
      d += p[j];
      d %= MOD;
      if (i >= 2 && i != n-1) {
        d -= dp[i-1][j];
        d = ((d % MOD) + MOD) % MOD;
      }
      p[j] += dp[i+1][j];
      p[j] %= MOD;
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= k; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  i64 ans = dp[n][k];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
