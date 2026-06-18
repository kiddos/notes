#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<i64>> c(4, vector<i64>(n+1));
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
    }
  }

  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> degree(n+1);
  for (auto [u, v] : edges) {
    degree[u]++;
    degree[v]++;
  }

  for (int node = 1; node <= n; ++node) {
    if (degree[node] >= 3) {
      cout << "-1" << endl;
      return;
    }
  }

  vector<int> chain;
  auto dfs = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }
    chain.push_back(node);
  };

  int start_node = -1;
  for (int node = 1; node <= n; ++node) {
    if (degree[node] == 1) {
      start_node = node;
      break;
    }
  }

  dfs(dfs, start_node, start_node);
  vector<vector<int>> possible = {
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1}
  };

  i64 ans1 = numeric_limits<i64>::max();
  vector<int> ans2(n+1);
  for (vector<int>& coloring : possible) {
    i64 total_cost = 0;
    for (int i = 0; i < n; ++i) {
      int color = coloring[i%3];
      int node = chain[i];
      total_cost += c[color][node];
    }
    if (total_cost < ans1) {
      ans1 = total_cost;
      for (int i = 0; i < n; ++i) {
        int color = coloring[i%3];
        int node = chain[i];
        ans2[node] = color;
      }
    }
  }

  cout << ans1 << endl;
  for (int node = 1; node <= n; ++node) {
    cout << ans2[node] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
