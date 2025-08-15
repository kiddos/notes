#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool has_cycle(vector<vector<int>>& adj, int n) {
  vector<int> state(n+1);
  auto dfs = [&](const auto& self, int node, int p) {
    if (state[node]) {
      return state[node] == 1;
    }

    state[node] = 1;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      if (self(self, next_node, node)) {
        return true;
      }
    }
    state[node] = 2;
    return false;
  };

  return dfs(dfs, 1, 1);
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (has_cycle(adj, n)) {
    // cout << "found cycle" << endl;
    cout << "0" << endl;
    return;
  }

  vector<int> degree(n+1);
  for (auto [u, v] : edges) {
    degree[u]++;
    degree[v]++;
  }

  constexpr int MOD = 1e9 + 7;
  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  int total_none_leaf = 0;
  i64 p = 1;
  for (int node = 1; node <= n; ++node) {
    if (degree[node] > 1) {
      int leaf_count = 0, none_leaf_count = 0;
      for (int next_node : adj[node]) {
        if (degree[next_node] == 1) {
          leaf_count++;
        } else {
          none_leaf_count++;
        }
      }

      p *= f[leaf_count];
      p %= MOD;

      if (none_leaf_count > 2) {
        // cout << "too many none leaf" << endl;
        cout << "0" << endl;
        return;
      }

      total_none_leaf++;
    }
  }

  // swap north and south
  p *= 2;
  p %= MOD;

  // swap -> to <-
  if (total_none_leaf > 1) {
    p *= 2;
    p %= MOD;
  }
  cout << p << endl;
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
