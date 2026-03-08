#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  constexpr int inf = 1e9;
  vector<vector<int>> dp(n+1, vector<int>(m, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dp[i][j] < inf) {
        int j2 = (j+1) % m;
        if (i+1 <= n) {
          dp[i+1][j2] = min(dp[i+1][j2], dp[i][j]+1);
        }
        if (i+2 <= n) {
          dp[i+2][j2] = min(dp[i+2][j2], dp[i][j]+1);
        }
      }
    }
  }
  if (dp[n][0] < inf) {
    cout << dp[n][0] << endl;
  } else {
    cout << "-1" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
