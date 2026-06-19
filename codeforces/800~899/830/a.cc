#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, p = 0;
  cin >> n >> k >> p;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  constexpr i64 inf = 1e18;
  vector<vector<i64>> dp(n+1, vector<i64>(k+1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[i] - b[j]) + abs(b[j] - p)));
      dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
    }
  }
  i64 ans = inf;
  for (int j = n; j <= k; ++j) {
    ans = min(ans, dp[n][j]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
