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
  vector<int> degree(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  vector<int> degree1(n+1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void{
    for (int next_node : adj[node]) {
      if (degree[next_node] == 1) {
        degree1[node]++;
      }
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }
  };

  dfs1(dfs1, 1, 1);

  int total_degree1 = 0;
  for (int node = 1; node <= n; ++node) {
    if (degree[node] == 1) {
      total_degree1++;
    }
  }

  int ans = n;
  for (int node = 1; node <= n; ++node) {
    int dont_move = degree1[node];
    int move = total_degree1 - dont_move - (degree[node] == 1 ? 1 : 0);
    ans = min(ans, move);
  }
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
