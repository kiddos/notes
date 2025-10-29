#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> colors(n+1);
  auto dfs = [&](const auto& self, int node, int color) -> bool {
    if (colors[node]) {
      return color == colors[node];
    }
    colors[node] = color;

    for (int next_node : adj[node]) {
      if (!self(self, next_node, 3 - color)) {
        return false;
      }
    }
    return true;
  };

  for (int i = 1; i <= n; ++i) {
    if (!colors[i]) {
      if (!dfs(dfs, i, 1)) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
