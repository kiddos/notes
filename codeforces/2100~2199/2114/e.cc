#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
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

  vector<i64> values(2);
  vector<i64> ans(n+1);
  vector<multiset<i64>> min_prefixes(2);
  min_prefixes[0].insert(0);
  min_prefixes[1].insert(0);

  auto dfs = [&](const auto& self, int node, int p, int d) -> void {
    int parity = d % 2;
    values[parity] += a[node];
    i64 current_prefix = values[parity] - values[1-parity];
    i64 min_prefix = *min_prefixes[parity].begin();
    ans[node] = current_prefix - min_prefix;
    min_prefixes[parity].insert(current_prefix);
    min_prefixes[1-parity].insert(-current_prefix);
    // cout << "node=" << node << ":" << values[parity] << "," << values[1-parity] << endl;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node, d+1);
    }
    values[parity] -= a[node];
    min_prefixes[parity].erase(min_prefixes[parity].find(current_prefix));
    min_prefixes[1-parity].erase(min_prefixes[1-parity].find(-current_prefix));
  };

  dfs(dfs, 1, 1, 0);

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
