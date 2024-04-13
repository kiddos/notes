#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  }

  int x = gcd(a[0][0], a[n-1][m-1]);

  vector<vector<bool>> dp(n, vector<bool>(m));
  auto can_reach = [&](int f) -> bool {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) dp[i][j] = false;
    }

    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i][j]) {
          if (i+1 < n && a[i+1][j] % f == 0) dp[i+1][j] = true;
          if (j+1 < m && a[i][j+1] % f == 0) dp[i][j+1] = true;
        }
      }
    }
    return dp[n-1][m-1];
  };
  
  int ans = 1;
  for (int d = 1; d*d <= x; ++d) {
    if (x % d == 0) {
      if (can_reach(d)) {
        ans = max(ans, d);
      }
      if (can_reach(x / d)) {
        ans = max(ans, x / d);
      }
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
