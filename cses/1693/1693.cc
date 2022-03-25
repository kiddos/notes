#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<pair<int, int>>& edges) {
  vector<vector<int>> adj(n);
  vector<int> indegree(n), outdegree(n);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    indegree[v]++;
    outdegree[u]++;
  }

  if (outdegree[0] - indegree[0] != 1) return {};
  if (indegree[n-1] - outdegree[n-1] != 1) return {};
  for (int node = 1; node < n-1; ++node) {
    if (outdegree[node] != indegree[node]) return {};
  }

  vector<int> path;
  function<void(int)> dfs = [&](int node) {
    while (!adj[node].empty()) {
      int next_node = adj[node].back();
      adj[node].pop_back();
      dfs(next_node);
    }
    path.push_back(node+1);
  };
  dfs(0);

  for (int node = 0; node < n; ++node) if (!adj[node].empty()) return {};
  reverse(path.begin(), path.end());
  return path;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u-1, v-1);
  }

  vector<int> ans = solve(n, edges);
  if (ans.size() == 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int node : ans) {
      cout << node << ' ';
    }
    cout << '\n';
  }
  cout.flush();
  return 0;
}
