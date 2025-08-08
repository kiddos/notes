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

  vector<bool> results(n+1);
  auto dfs1 = [&](const auto& self, int node, int p) -> bool {
    int children_count = 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      children_count++;
    }
    if (children_count == 0) {
      return results[node] = false;
    }

    bool ans = false;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      bool result = self(self, next_node, node);
      if (!result) {
        ans = true;
      }
    }
    return results[node] = ans;
  };

  dfs1(dfs1, 1, 1);
  // for (int node = 1; node <= n; ++node) {
  //   cout << results[node] << " ";
  // }
  // cout << endl;

  vector<bool> ans(n+1);
  ans[1] = results[1];

  auto dfs2 = [&](const auto& self, int node, int p, bool from_parent) -> void {
    vector<int> count(2);
    count[from_parent]++;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      count[results[next_node]]++;
    }
    // cout << "node=" << node << ":" << count[0] <<"," << count[1] << ", from_parent=" << from_parent << endl;
    if (count[0]) {
      ans[node] = true;
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      count[results[next_node]]--;
      bool node_from_parent = count[0] > 0;
      self(self, next_node, node, node_from_parent);
      count[results[next_node]]++;
    }
  };

  dfs2(dfs2, 1, 1, true);

  for (int i = 0; i < t; ++i) {
    if (ans[u[i]]) {
      cout << "Ron\n";
    } else {
      cout << "Hermione\n";
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
