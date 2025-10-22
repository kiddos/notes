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

  // eulerian path
  // 2 nodes have odd degree
  // according to the problem
  // we have to reach n from 1
  // so node 1 and node n must have net degree != 0
  // and other node must 0 net degree
  vector<vector<pair<int,int>>> adj(n+1);
  vector<int> degree(n+1);
  for (int i = 0; i < m; ++i) {
    auto [a, b] = edges[i];
    adj[a].push_back({b, i});
    degree[a]--;
    degree[b]++;
  }

  for (int node = 2; node < n; ++node) {
    if (degree[node] != 0) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  if (degree[1] != -1 || degree[n] != 1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<int> ans;
  vector<bool> used(m);
  auto dfs = [&](const auto& self, int node) -> void {
    while (!adj[node].empty()) {
      auto [next_node, idx] = adj[node].back();
      adj[node].pop_back();
      if (!used[idx]) {
        used[idx] = true;
        self(self, next_node);
      }
    }
    ans.push_back(node);
  };

  dfs(dfs, 1);
  reverse(ans.begin(), ans.end());

  for (int i = 0; i < m; ++i) {
    if (!used[i]) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  for (int node : ans) {
    cout << node << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
