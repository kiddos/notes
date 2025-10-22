#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;

  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    a--;
    b--;
    edges.push_back({a, b, c});
  }

  constexpr i64 inf = 1e18;
  vector<vector<i64>> dp(n, vector<i64>(n, inf));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
  }
  for (auto [a, b, c] : edges) {
    dp[a][b] = min(dp[a][b], (i64)c);
    dp[b][a] = min(dp[b][a], (i64)c);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    i64 ans = dp[a][b];
    if (ans >= inf) {
      cout << "-1" << endl;
    } else {
      cout << ans << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
