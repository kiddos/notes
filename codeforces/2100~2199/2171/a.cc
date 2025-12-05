#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> dp(n+1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    if (i+2 <= n) {
      dp[i+2] += dp[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i+4 <= n) {
      dp[i+4] += dp[i];
    }
  }
  cout << dp[n] << endl;
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
