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
    adj[b].push_back(a);
  }

  vector<int> ordering;
  vector<int> state(n+1);
  auto dfs = [&](const auto& self, int node) -> bool {
    if (state[node]) {
      return state[node] == 1;
    }
    state[node] = 1;
    for (int prev_node : adj[node]) {
      if (self(self, prev_node)) {
        return true;
      }
    }
    state[node] = 2;
    ordering.push_back(node);
    return false;
  };

  for (int i = 1; i <= n; ++i) {
    if (dfs(dfs, i)) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  for (int node : ordering) {
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
