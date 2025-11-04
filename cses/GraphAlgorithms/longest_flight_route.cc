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
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
  }

  vector<bool> visited(n+1);
  auto dfs1 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      self(self, next_node);
    }
  };

  dfs1(dfs1, 1);

  if (!visited[n]) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  constexpr int inf = 1e9;
  vector<int> memo(n+1, -1);
  vector<int> next(n+1);
  auto dfs2 = [&](const auto& self, int node) -> int {
    if (node == n) {
      return 0;
    }
    if (memo[node] >= 0) {
      return memo[node];
    }
    int ans = -inf;
    for (int next_node : adj[node]) {
      int result = self(self, next_node) + 1;
      if (result >= 0 && result > ans) {
        ans = result;
        next[node] = next_node;
      }
    }
    return memo[node] = ans;
  };

  dfs2(dfs2, 1);

  int current = 1;
  vector<int> ans = {1};
  while (current != n) {
    current = next[current];
    ans.push_back(current);
  }

  cout << ans.size() << endl;
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
