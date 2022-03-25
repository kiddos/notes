#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<pair<int, int>>& edges) {
  vector<vector<pair<int, int>>> adj(n);
  vector<int> degree(n);
  for (int i = 0; i < edges.size(); ++i) {
    auto [u, v] = edges[i];
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  for (int node = 0; node < n; ++node) {
    if (adj[node].size() % 2 == 1) {
      return {};
    }
  }

  vector<int> path;
  vector<bool> used(edges.size());
  function<void(int)> dfs = [&](int node) {
    while (!adj[node].empty()) {
      auto [next_node, index] = adj[node].back();
      adj[node].pop_back();
      if (!used[index]) {
        used[index] = true;
        dfs(next_node);
      }
    }
    path.push_back(node+1);
  };

  dfs(0);
  reverse(path.begin(), path.end());
  if (path.size() != edges.size()+1) return {};
  return path;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i){
    int u = 0, v = 0;
    cin >> u >> v;
    edges[i].first = u-1;
    edges[i].second = v-1;
  }

  vector<int> ans = solve(n, edges);
  if (ans.size() == 0) cout << "IMPOSSIBLE\n";
  else {
    for (int a :ans) cout << a << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
