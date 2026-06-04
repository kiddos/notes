#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.push_back({a, b});
  }

  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    auto [a, b] = edges[i];
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
  }

  int id = 0;
  vector<int> ids(n+1), lowlink(n+1);
  vector<bool> visited(n+1);
  vector<int> dir(m);
  bool found_bridge = false;
  auto dfs = [&](const auto& self, int node, int parent) -> void {
    visited[node] = true;
    ids[node] = lowlink[node] = ++id;
    for (auto [next_node, edge_idx] : adj[node]) {
      if (next_node == parent) {
        continue;
      }

      if (!dir[edge_idx]) {
        pair<int,int> p1 = edges[edge_idx];
        pair<int,int> p2 = {node, next_node};
        if (p1 == p2) {
          dir[edge_idx] = 1;
        } else {
          dir[edge_idx] = -1;
        }
      }

      if (!visited[next_node]) {
        self(self, next_node, node);
        lowlink[node] = min(lowlink[node], lowlink[next_node]);
        if (ids[node] < lowlink[next_node]) {
          found_bridge = true;
        }
      } else {
        lowlink[node] = min(lowlink[node], lowlink[next_node]);
      }
    }
  };

  dfs(dfs, 1, -1);

  if (found_bridge) {
    cout << "0" << endl;
    return;
  }

  for (int i = 0; i < m; ++i) {
    auto [a, b] = edges[i];
    if (dir[i] == 1) {
      cout << a << " " << b << endl;
    } else {
      cout << b << " " << a << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
