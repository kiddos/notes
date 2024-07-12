#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> lowrank(n+1);
  vector<int> ids(n+1);
  int id = 0;
  set<pair<int,int>> bridges;
  function<void(int, int)> dfs1 = [&](int node, int parent) {
    ids[node] = lowrank[node] = ++id;
    for (int child : adj[node]) if (child != parent) {
      if (!ids[child]) {
        dfs1(child, node);

        lowrank[node] = min(lowrank[node], lowrank[child]);
        if (ids[node] < lowrank[child]) {
          int u = min(node, child);
          int v = max(node, child);
          bridges.insert({u, v});
        }
      } else {
        lowrank[node] = min(lowrank[node], lowrank[child]);
      }
    }
  };

  for (int node = 1; node <= n; ++node) {
    if (!ids[node]) {
      dfs1(node, -1);
    }
  }

  // cout << "bridges: " << endl;
  // for (auto b : bridges) {
  //   cout << b.first << " <-> " << b.second << endl;
  // }

  i64 ans = (i64) n * (n-1) / 2;
  vector<bool> visited(n+1);
  function<int(int)> dfs2 = [&](int node) -> int {
    visited[node] = true;
    int total = 1;
    for (int child : adj[node]) {
      if (!visited[child]) {
        int child_count = dfs2(child);
        int u = min(node, child);
        int v = max(node, child);
        if (bridges.count({u, v})) {
          i64 c1 = child_count, c2 = n - child_count;
          ans = min(ans, c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2);
        }
        total += child_count;
      }
    }
    return total;
  };

  dfs2(1);
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
