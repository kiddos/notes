#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
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

  vector<int> u(t);
  for (int i = 0; i < t; ++i) {
    cin >> u[i];
  }

  auto dfs = [&](const auto& self, int node, int p) -> bool {
    int children_count = 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      children_count++;
    }
    if (children_count == 0) {
      return false;
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      bool result = self(self, next_node, node);
      if (!result) {
        return true;
      }
    }
    return false;
  };

  bool result = dfs(dfs, u[0], -1);
  if (result) {
    cout << "Ron" << endl;
  } else {
    cout << "Hermione" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
