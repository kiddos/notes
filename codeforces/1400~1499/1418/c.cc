#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  constexpr int inf = 1e9;
  vector<vector<int>> dp(n+1, vector<int>(2, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i+1][1] = min(dp[i+1][1], dp[i][0] + a[i]);
    dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
    if (i+2 <= n) {
      dp[i+2][1] = min(dp[i+2][1], dp[i][0] + a[i] + a[i+1]);
      dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
    }
  }
  int ans = min(dp[n][0], dp[n][1]);
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
