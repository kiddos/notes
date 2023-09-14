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

  vector<int> in(n+1), out(n+1);
  for (auto& [u, v] : edges) {
    in[v]++;
    out[u]++;
  }

  unordered_set<int> remove;
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    if (in[v] == 1) {
      remove.insert(i);
    }
    if (out[u] == 1) {
      remove.insert(i);
    }
  }

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; ++i) if (!remove.count(i)) {
    auto [u, v] = edges[i];
    adj[u].push_back(v);
  }

  vector<int> depth(n+1);
  function<int(int)> dfs = [&](int node) -> int {
    if (depth[node]) {
      return depth[node];
    }
    int ans = 1;
    for (int next_node : adj[node]) {
      ans = max(ans, dfs(next_node) + 1);
    }
    return depth[node] = ans;
  };

  int ans = 0;
  for (int node = 1; node <= n; ++node) {
    ans = max(ans, dfs(node));
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
