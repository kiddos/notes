#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> dp(n+1);
  dp[0] = 1;
  constexpr int MOD = 1e9 + 7;
  for (int val = 1; val <= n; ++val) {
    for (int d = 1; d <= 6; ++d) {
      if (val-d >= 0) {
        dp[val] += dp[val-d];
        dp[val] %= MOD;
      }
    }
  }
  cout << dp[n] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
