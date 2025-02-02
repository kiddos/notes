#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(m, {numeric_limits<int>::max(), numeric_limits<int>::min()}));
  dp[0][0] = {0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i > 0) {
        dp[i][j].first = min(dp[i][j].first, dp[i-1][j].first + (j+1));
        dp[i][j].second = max(dp[i][j].second, dp[i-1][j].first + (j+1));
      }
      if (j > 0) {
        dp[i][j].first = min(dp[i][j].first, dp[i][j-1].first + (i+1));
        dp[i][j].second = max(dp[i][j].second, dp[i][j-1].first + (i+1));
      }
    }
  }

  if (k >= dp[n-1][m-1].first && k <= dp[n-1][m-1].second) {
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
