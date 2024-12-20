#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<vector<int>> dp(n+1, vector<int>(2));
  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    char c = s[i-1];
    if (c == '1') {
      dp[i][1] = dp[i-1][0] + 1;
    } else if (c == '0') {
      dp[i][0] = dp[i-1][1] + 1;
    } else if (c == '?') {
      dp[i][0] = dp[i-1][1] + 1;
      dp[i][1] = dp[i-1][0] + 1;
    }
    ans += max(dp[i][0], dp[i][1]);
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
