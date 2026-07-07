#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, s = 0;
  cin >> n >> m >> s;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
  }

  vector<bool> can_reach(n+1);
  queue<int> q;
  q.push(s);
  can_reach[s] = true;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      for (int next_node : adj[node]) {
        if (can_reach[next_node]) {
          continue;
        }
        can_reach[next_node] = true;
        q.push(next_node);
      }
    }
  }

  vector<int> cannot_reach;
  for (int node = 1; node <= n; ++node) {
    if (!can_reach[node]) {
      cannot_reach.push_back(node);
    }
  }

  vector<int> ordering;
  vector<bool> visited(n+1);
  auto dfs1 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      self(self, next_node);
    }
    ordering.push_back(node);
  };
  for (int node : cannot_reach) {
    dfs1(dfs1, node);
  }

  auto dfs2 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      self(self, next_node);
    }
  };

  reverse(ordering.begin(), ordering.end());
  int ans = 0;
  fill(visited.begin(), visited.end(), false);
  for (int node : ordering) {
    if (can_reach[node]) {
      continue;
    }
    if (visited[node]) {
      continue;
    }
    dfs2(dfs2, node);
    ans++;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
