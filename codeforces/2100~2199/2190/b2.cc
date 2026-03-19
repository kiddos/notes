#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  // in this question
  // we need to observe that
  // a better subsequence should have )(( as a subsequence inside
  // count number of subsequence with )((
  vector<vector<vector<i64>>> dp(n+1, vector<vector<i64>>(n+1, vector<i64>(4)));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    vector<vector<vector<i64>>> dp2 = dp;
    for (int b = 0; b < n; ++b) {
      for (int l = 0; l < n; ++l) {
        for (int k = 0; k < 4; ++k) {
          if (s[i] == '(' && (k == 1 || k == 2)) {
            dp2[b+1][l+1][k+1] += dp[b][l][k];
            dp2[b+1][l+1][k+1] %= MOD;
          } else if (s[i] == '(' && (k == 0 || k == 3)) {
            dp2[b+1][l+1][k] += dp[b][l][k];
            dp2[b+1][l+1][k] %= MOD;
          } else if (s[i] == ')' && k == 0 && b > 0) {
            dp2[b-1][l+1][k+1] += dp[b][l][k];
            dp2[b-1][l+1][k+1] %= MOD;
          } else if (s[i] == ')' && (k == 1 || k == 2 || k == 3) && b > 0) {
            dp2[b-1][l+1][k] += dp[b][l][k];
            dp2[b-1][l+1][k] %= MOD;
          }
        }
      }
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  for (int l = 2; l <= n; ++l) {
    ans += dp[0][l][3] * (l-2);
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
