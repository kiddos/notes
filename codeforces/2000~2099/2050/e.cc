#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b, c;
  cin >> a >> b >> c;
  int n = a.length(), m = b.length();
  constexpr int inf = 100000000;
  vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i-1][0] + (c[i-1] != a[i-1]);
  }
  for (int j = 1; j <= m; ++j) {
    dp[0][j] = dp[0][j-1] + (c[j-1] != b[j-1]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int k = i+j-1;
      if (c[k] == a[i-1]) {
        dp[i][j] = min(dp[i][j], dp[i-1][j]);
      }
      if (c[k] == b[j-1]) {
        dp[i][j] = min(dp[i][j], dp[i][j-1]);
      }
      dp[i][j] = min({dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1});
    }
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int ans = dp[n][m];
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
