#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
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

  // find a node with 2 edges
  int start = 0;
  for (int node = 1; node <= n; ++node) {
    if (adj[node].size() == 2) {
      start = node;
      break;
    }
  }

  vector<pair<int,int>> ans;
  auto dfs = [&](const auto& self, int node, int p, bool in) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      if (in) {
        ans.emplace_back(node, next_node);
      } else {
        ans.emplace_back(next_node, node);
      }
      self(self, next_node, node, !in);
    }
  };

  if (!start) {
    cout << "NO" << endl;
    return;
  }

  int node1 = adj[start][0];
  int node2 = adj[start][1];
  ans.emplace_back(node2, start);
  ans.emplace_back(start, node1);
  dfs(dfs, node1, start, false);
  dfs(dfs, node2, start, true);

  cout << "YES" << endl;
  for (auto [u, v] : ans) {
    cout << u << " " << v << endl;
  }
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
