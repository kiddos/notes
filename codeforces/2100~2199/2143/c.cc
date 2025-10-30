#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,4>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0, x = 0, y = 0;
    cin >> u >> v >> x >> y;
    edges.push_back({u, v, x, y});
  }
  
  vector<vector<int>> adj(n+1);
  for (auto [u, v, x, y] : edges) {
    if (x >= y) {
      adj[u].push_back(v);
    } else {
      adj[v].push_back(u);
    }
  }

  vector<bool> visited(n+1);
  vector<int> ordering;
  auto dfs = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      self(self, next_node);
    }
    ordering.push_back(node);
  };

  for (int i = 1; i <= n; ++i) {
    dfs(dfs, i);
  }

  vector<int> ans(n+1);
  for (int i = 0; i < n; ++i) {
    ans[ordering[i]] = i+1;
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
