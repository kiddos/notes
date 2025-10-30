#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
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

  vector<int> node_count(n+1, 1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      node_count[node] += node_count[next_node];
    }
  };

  dfs1(dfs1, 1, 1);

  int f = 0;
  for (int i = 1; i <= n; ++i) {
    if (node_count[i] >= k) {
      f++;
    }
  }

  i64 ans = 0;
  auto dfs2 = [&](const auto& self, int node, int p) -> void {
    ans += f;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      // next node becomes root
      int current_node_count = n - node_count[next_node];
      bool add = node_count[next_node] < k && current_node_count >= k;
      bool sub = node_count[next_node] >= k && current_node_count < k;
      if (add) {
        f++;
      }
      if (sub) {
        f--;
      }

      self(self, next_node, node);

      if (add) {
        f--;
      }
      if (sub) {
        f++;
      }
    }
  };

  dfs2(dfs2, 1, 1);

  cout << ans << endl;
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
