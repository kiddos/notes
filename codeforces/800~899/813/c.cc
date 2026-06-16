#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v= 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto dfs = [&](const auto& self, int node, int p, vector<int>& dists) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dists[next_node] = dists[node] + 1;
      self(self, next_node, node, dists);
    }
  };

  vector<int> bob_dists(n+1);
  dfs(dfs, x, x, bob_dists);

  vector<int> alice_dists(n+1);
  dfs(dfs, 1, 1, alice_dists);

  int ans = 0;
  for (int node = 1; node <= n; ++node) {
    if (bob_dists[node] < alice_dists[node]) {
      ans = max(ans, alice_dists[node] * 2);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
