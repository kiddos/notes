#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> dp(n, vector<int>(n));
  if (s[0][0] != '*') {
    dp[0][0] = 1;
  }
  for (int j = 1; j < n; ++j) {
    if (s[0][j] != '*') {
      dp[0][j] += dp[0][j-1];
    }
  }
  for (int i = 1; i < n; ++i) {
    if (s[i][0] != '*') {
      dp[i][0] += dp[i-1][0];
    }
  }
  constexpr int MOD = 1e9 + 7;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (s[i][j] != '*') {
        dp[i][j] += dp[i][j-1];
        dp[i][j] %= MOD;
        dp[i][j] += dp[i-1][j];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[n-1][n-1] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
