#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  constexpr i64 INF = 1e18;

  i64 ans = 0;
  vector<i64> dp(n+1, -INF);
  function<void(int,int)> dfs = [&](int node, int p) {
    vector<i64> children;
    for (int next_node : adj[node]) if (next_node != p) {
      dfs(next_node, node);
      children.push_back(dp[next_node]);
    }
    vector<i64> dp2(4, -INF);
    dp2[0] = 0;
    for (i64 d : children) {
      for (int i = 3; i >= 0; --i) {
        dp2[min(i+1, 3)] = max(dp2[min(i+1, 3)], dp2[i] + d);
      }
    }

    dp[node] = max(dp[node], a[node]);
    // cannot add a[node] because this node will be compressed
    dp[node] = max(dp[node], dp2[1]);
    dp[node] = max(dp[node], a[node] + dp2[2]);
    dp[node] = max(dp[node], a[node] + dp2[3]);

    ans = max(ans, a[node]);
    ans = max(ans, a[node] + dp2[1]);
    // cannot add a[node] because this node will be compressed
    ans = max(ans, dp2[2]);
    ans = max(ans, a[node] + dp2[3]);
  };

  dfs(1, -1);

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
