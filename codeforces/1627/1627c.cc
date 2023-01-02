#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<vector<int>>& edges) {
  vector<vector<pair<int, int>>> adj(n);
  vector<int> degree(n);
  for (int i = 0; i < edges.size(); ++i) {
    int u = edges[i][0], v = edges[i][1];
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    degree[u]++;
    degree[v]++;
    if (degree[u] >= 3 || degree[v] >= 3) return {};
  }

  auto find_start = [&]() {
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) return i;
    }
    return 0;
  };

  vector<int> ans(n-1);
  int root = find_start();
  int k = 0;
  function<void(int,int)> dfs = [&](int node, int parent) {
    for (auto [next_node, index] : adj[node]) {
      if (next_node == parent) continue;
      ans[index] = k++ % 2 == 0 ? 2 : 3;
      dfs(next_node, node);
    }
  };
  dfs(root, -1);
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<vector<int>> edges(n-1, vector<int>(2));
    for (int i = 0; i < n-1; ++i) {
      cin >> edges[i][0] >> edges[i][1];
      edges[i][0]--;
      edges[i][1]--;
    }

    vector<int> ans = solve(n, edges);
    if (ans.size() == 0) cout << "-1";
    else {
      for (int a : ans) cout << a << ' ';
    }
    cout << '\n';
  }
  cout << flush;
  return 0;
}
