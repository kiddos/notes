#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n+1, vector<int>(n+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i-1][j] + (i-j == a[i]);
      if (j > 0) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
      }
    }
  }

  int ans = numeric_limits<int>::max();
  for (int j = 0; j <= n; ++j) {
    if (dp[n][j] >= k) {
      ans = min(ans, j);
    }
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
