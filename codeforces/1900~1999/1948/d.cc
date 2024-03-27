#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int m = n / 2;
  int ans = 0;
  for (int len = 1; len <= m; ++len) {
    vector<int> dp(n);
    for (int i = 0; i <= n-len; ++i) {
      if (s[i] == s[i+len] || s[i] == '?' || s[i+len] == '?') {
        dp[i] = (i > 0 ? dp[i-1] : 0) + 1;
      }

      if (dp[i] >= len) {
        ans = max(ans, len*2);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}