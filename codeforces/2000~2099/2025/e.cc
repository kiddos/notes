#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  constexpr int MOD = 998244353;
  vector<i64> dp1(m+1);
  dp1[0] = 1;
  for (int i = 0; i < m; ++i) {
    vector<i64> dp2(m+1);
    for (int j = 0; j <= i; ++j) {
      if (j+1 <= m) {
        dp2[j+1] += dp1[j];
        dp2[j+1] %= MOD;
      }
      if (j > 0) {
        dp2[j-1] += dp1[j];
        dp2[j-1] %= MOD;
      }
    }
    dp1 = std::move(dp2);
  }

  vector<i64> balance_count = dp1;
  // for (int i = 0; i <= m; ++i) {
  //   cout << balance_count[i] << " ";
  // }
  // cout << endl;

  vector<i64> dp = dp1;
  for (int i = 1; i < n; ++i) {
    vector<i64> dp2(m+1);
    for (int j = 0; j <= m; j += 2) {
      for (int k = 0; k <= j; k += 2) {
        dp2[j-k] += (dp[j] * balance_count[k]) % MOD;
        dp2[j-k] %= MOD;
      }
    }
    dp = std::move(dp2);
  }

  int ans = dp[0];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
