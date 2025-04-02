#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, st = 0, en = 0;
  cin >> n >> st >> en;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> path = {st};
  function<bool(int,int)> find_path = [&](int node, int p) -> bool {
    if (node == en) {
      return true;
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      path.push_back(next_node);
      if (find_path(next_node, node)) {
        return true;
      }
      path.pop_back();
    }
    return false;
  };

  find_path(st, 0);
  set<int> s(path.begin(), path.end());

  vector<int> ans;
  function<void(int,int)> dfs1 = [&](int node, int p) {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      if (s.count(next_node)) {
        continue;
      }
      dfs1(next_node, node);
    }
    ans.push_back(node);
  };

  for (int i = 0; i < (int)path.size(); ++i) {
    dfs1(path[i], 0);
  }

  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
