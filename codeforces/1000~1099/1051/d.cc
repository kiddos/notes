#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


// 0 -> 00
// 1 -> 01
// 2 -> 10
// 3 -> 11

constexpr int MOD = 998244353;
void mod_add(i64& x, i64 y) {
  x += y;
  x %= MOD;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<vector<i64>> dp(k+3, vector<i64>(4));
  dp[1][0] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;
  dp[1][3] = 1;
  for (int i = 2; i <= n; ++i) {
    vector<vector<i64>> dp2(k+3, vector<i64>(4));
    for (int j = 1; j <= k; ++j) {
      mod_add(dp2[j][0], dp[j][0]);
      mod_add(dp2[j][0], dp[j][1]);
      mod_add(dp2[j][0], dp[j][2]);
      mod_add(dp2[j+1][0], dp[j][3]);

      mod_add(dp2[j+1][1], dp[j][0]);
      mod_add(dp2[j][1], dp[j][1]);
      mod_add(dp2[j+2][1], dp[j][2]);
      mod_add(dp2[j+1][1], dp[j][3]);

      mod_add(dp2[j+1][2], dp[j][0]);
      mod_add(dp2[j+2][2], dp[j][1]);
      mod_add(dp2[j][2], dp[j][2]);
      mod_add(dp2[j+1][2], dp[j][3]);

      mod_add(dp2[j+1][3], dp[j][0]);
      mod_add(dp2[j][3], dp[j][1]);
      mod_add(dp2[j][3], dp[j][2]);
      mod_add(dp2[j][3], dp[j][3]);
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  for (int t = 0; t < 4; ++t) {
    mod_add(ans, dp[k][t]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
