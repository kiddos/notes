#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m ; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
  }

  vector<int> state(n+1);
  deque<int> path;
  auto dfs = [&](const auto& self, int node) {
    path.push_back(node);
    if (state[node]) {
      if (state[node] == 1) {
        return true;
      }

      path.pop_back();
      return false;
    }
    state[node] = 1;

    for (int next_node : adj[node]) {
      if (self(self, next_node)) {
        return true;
      }
    }
    path.pop_back();
    state[node] = 2;
    return false;
  };

  for (int i = 1; i <= n; ++i) {
    if (!state[i]) {
      if (dfs(dfs, i)) {
        while (path.front() != path.back()) {
          path.pop_front();
        }

        cout << path.size() << endl;
        for (int node : path) {
          cout << node << " ";
        }
        cout << endl;
        return;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
