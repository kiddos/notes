#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  constexpr ll MAX_VAL = 1e18;
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, MAX_VAL));
  for (int i = 1; i <= n; ++i) dp[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0, y = 0;
    cin >> u >> v >> y;
    dp[u][v] = dp[v][u] = y;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  if (dp[1][n] >= MAX_VAL) {
    cout << "inf" << endl;
    return;
  }

  vector<pair<string, ll>> ans;
  string s(n, '0');
  vector<bool> played(n+1);
  for (int i = 1; i <= n; ++i) if (dp[1][i] == 0) {
    s[i-1] = '1';
    played[i] = true;
  }

  ll last = 0;
  while (!played[n]) {
    ll dist = dp[1][n];
    for (int i = 1; i <= n; ++i) if (!played[i]) {
      dist = min(dist, dp[1][i]);
    }

    ans.push_back({s, dist - last});
    for (int i = 1; i <= n; ++i) if (dp[1][i] == dist) {
      s[i-1] = '1';
      played[i] = true;
    }
    last = dist;
  }

  cout << dp[1][n] << " " << ans.size() << endl;
  for (auto& [s, t] : ans) {
    cout << s << " " << t << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
