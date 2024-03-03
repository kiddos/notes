#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  string s;
  cin >> s;
  vector<i64> dp(n+5);
  for (int i = n; i >= 1; --i) {
    if (s[i-1] == '1') {
      i64 len = n-i+1;
      dp[i] = dp[i+3] + len;
    } else {
      dp[i] = dp[i+1];
    }
  }

  i64 ans = accumulate(dp.begin(), dp.end(), 0LL);
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
