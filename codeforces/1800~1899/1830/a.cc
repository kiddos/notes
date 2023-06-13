#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }

  queue<array<int,3>> q;
  q.push({1, 0, 1});
  vector<bool> visited(n+1);
  visited[1] = true;


  int ans = 0;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [node, ordering, reading] = q.front();
      q.pop();

      ans = max(ans, reading);

      // cout << "node: " << node << ", reading: " << reading << endl;

      for (auto& [next_node, edge_order] : adj[node]) {
        if (visited[next_node]) continue;
        visited[next_node] = true;
        int reading2 = reading + (edge_order > ordering ? 0 : 1);
        q.push({next_node, edge_order, reading2});
      }
    }
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
