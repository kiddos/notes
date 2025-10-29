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
    adj[b].push_back(a);
  }

  vector<int> state(n+1);
  vector<int> path;
  int cycle_start = -1;
  auto dfs = [&](const auto& self, int node, int p) {
    if (state[node]) {
      if (state[node] == 1) {
        cycle_start = node;
        return true;
      }
      return false;
    }
    state[node] = 1;

    path.push_back(node);
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      if (self(self, next_node, node)) {
        return true;
      }
    }
    path.pop_back();
    state[node] = 2;
    return false;
  };

  for (int i = 1; i <= n; ++i) {
    if (!state[i]) {
      if (dfs(dfs, i, i)) {
        int idx = find(path.begin(), path.end(), cycle_start) - path.begin();
        vector<int> ans;
        for (int j = idx; j < (int)path.size(); ++j) {
          ans.push_back(path[j]);
        }
        ans.push_back(cycle_start);

        cout << ans.size() << endl;
        for (int node : ans) {
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
