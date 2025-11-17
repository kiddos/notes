#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }
  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<i64> dp(n+1);
  vector<int> node_count(n+1, 1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      node_count[node] += node_count[next_node];
      dp[node] += dp[next_node];
    }
    dp[node] += node_count[node] - 1;
  };

  dfs1(dfs1, 1, 1);

  vector<i64> ans(n+1);
  ans[1] = dp[1];

  auto dfs2 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      ans[next_node] = ans[node] + n - 2 * node_count[next_node];
      self(self, next_node, node);
    }
  };

  dfs2(dfs2, 1, 1);

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
