#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<i64>> h(2, vector<i64>(n+1));
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> h[i][j];
    }
  }
  vector<vector<i64>> dp(2, vector<i64>(n+1));
  for (int j = 1; j <= n; ++j) {
    dp[0][j] = max({dp[1][j-1] + h[0][j], dp[0][j-1], dp[1][j-1]});
    dp[1][j] = max({dp[0][j-1] + h[1][j], dp[0][j-1], dp[1][j-1]});
  }
  i64 ans = max(dp[0][n], dp[1][n]);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
