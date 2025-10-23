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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<array<i64,2>> dp(n);
  dp[0][0] = dp[0][1] = 1;
  constexpr int MOD = 998244353;
  for (int i = 1; i < n; ++i) {
    if (a[i] >= a[i-1] && b[i] >= b[i-1]) {
      dp[i][0] += dp[i-1][0];
      dp[i][1] += dp[i-1][1];
    }
    if (a[i] >= b[i-1] && b[i] >= a[i-1]) {
      dp[i][0] += dp[i-1][1];
      dp[i][1] += dp[i-1][0];
    }
    dp[i][0] %= MOD;
    dp[i][1] %= MOD;
  }
  i64 ans = dp[n-1][0] + dp[n-1][1];
  ans %= MOD;
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
