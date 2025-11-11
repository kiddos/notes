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

  vector<array<int,2>> dp(n+1, {0, 0});
  auto dfs = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dp[node][0] += max(dp[next_node][1], dp[next_node][0]);
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dp[node][1] = max(dp[node][1], dp[node][0] - max(dp[next_node][0], dp[next_node][1]) + dp[next_node][0] + 1);
    }
  };

  dfs(dfs, 1, 1);
  int ans = max(dp[1][0], dp[1][1]);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
