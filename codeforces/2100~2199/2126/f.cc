#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<array<int,3>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0, c = 0;
    cin >> u >> v >> c;
    edges.push_back({u, v, c});
  }
  vector<vector<array<int,2>>> adj(n+1);
  for (auto [u, v, c] : edges) {
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  vector<pair<int,int>> parents(n+1, {0, 0});
  vector<map<int,i64>> children_cost(n+1);
  i64 cost = 0;
  auto dfs = [&](const auto& self, int node, int p) -> void {
    for (auto [next_node, c] : adj[node]) {
      if (next_node == p) {
        continue;
      }
      if (a[node] != a[next_node]) {
        cost += c;
      }
      children_cost[node][a[next_node]] += c;
      parents[next_node] = {node, c};
      self(self, next_node, node);
    }
  };

  dfs(dfs, 1, 1);

  auto change_color = [&](int node, int new_color) {
    if (a[node] == new_color) {
      return;
    }

    i64 remove = children_cost[node].count(new_color) ? children_cost[node][new_color] : 0;
    i64 add = children_cost[node].count(a[node]) ? children_cost[node][a[node]] : 0;
    cost -= remove;
    cost += add;
    auto [parent, edge_cost] = parents[node];
    if (parent) {
      children_cost[parent][a[node]] -= edge_cost;
      children_cost[parent][new_color] += edge_cost;
      if (a[parent] == a[node]) {
        cost += edge_cost;
      }
      if (a[parent] == new_color) {
        cost -= edge_cost;
      }
    }
    a[node] = new_color;
  };

  for (int i = 0; i < q; ++i) {
    int v = 0, x = 0;
    cin >> v >> x;
    change_color(v, x);
    cout << cost << endl;
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
