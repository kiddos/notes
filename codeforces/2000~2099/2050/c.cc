#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<bool> dp(9);
  dp[0] = true;
  for (char ch : s) {
    vector<bool> dp2(9);
    int c = ch -'0';
    for (int i = 0; i < 9; ++i) {
      dp2[(i+c)%9] = dp2[(i+c)%9] || dp[i];
      if (c == 2) {
        dp2[(i+4)%9] = dp2[(i+4)%9] || dp[i];
      }
      if (c == 3) {
        dp2[i] = dp2[i] || dp[i];
      }
    }
    dp = std::move(dp2);
  }
  bool ans = dp[0];
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
