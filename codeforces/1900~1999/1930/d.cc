#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// p=11111
// q=10101
//
// p=10
// q=10 or 01
// p=101
// q=010
// p=111
// q=010
// p=1001
// q=0110

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  // i64 ans = 0;
  constexpr int INF = numeric_limits<int>::max();
  vector<vector<int>> dp(n, vector<int>(n, INF));
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      int d = (r-1 >= l ? dp[l][r-1] : 0);
      // cout << "d=" << d << endl;
      if (s[r] == '1') {
        dp[l][r] = min(dp[l][r], d+1);
        if (r+1 < n) dp[l][r+1] = min(dp[l][r+1], d+1);
        if (r+2 < n) dp[l][r+2] = min(dp[l][r+2], d+1);
      } else {
        dp[l][r] = min(dp[l][r], d);
      }
      // for (int i = l; i <= r;) {
      //   if (s[i] == '1') {
      //     i += 3;
      //     dp[l][r]++;
      //   } else {
      //     i++;
      //   }
      // }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j < i) dp[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  i64 ans = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      ans += dp[l][r];
    }
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
