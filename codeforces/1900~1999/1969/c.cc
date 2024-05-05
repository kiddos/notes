#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// k = 2
// [1, 2, 100]

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr i64 INF = numeric_limits<i64>::max();
  vector<vector<i64>> dp(n+1, vector<i64>(k+1, INF));
  for (int j = 0; j <= k; ++j) dp[0][j] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j1 = 0; j1 <= k; ++j1) {
      i64 min_val = a[i];
      for (int len = 0; j1+len <= k; ++len) {
        if (i + len < n) {
          min_val = min(min_val, a[i+len]);
        }
        dp[min(i+len+1, n)][j1+len] = min(dp[min(i+len+1, n)][j1+len], dp[i][j1] + min_val * (len + 1));
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 0; j <= k; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[n][k] << endl;
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
