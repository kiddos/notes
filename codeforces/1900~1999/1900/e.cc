#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  vector<vector<int>> rev(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }

  vector<int> s;
  vector<bool> visited(n+1);
  function<void(int)> dfs1 = [&](int node) {
    if (visited[node]) {
      return;
    }

    visited[node] = true;
    for (int next_node : adj[node]) {
      dfs1(next_node);
    }
    s.push_back(node);
  };

  for (int node = 1; node <= n; ++node) {
    if (!visited[node]) {
      dfs1(node);
    }
  }

  function<void(int,vector<int>&)> dfs2 = [&](int node, vector<int>& components) {
    if (!visited[node]) {
      return;
    }

    visited[node] = false;
    components.push_back(node);
    for (int next_node : rev[node]) {
      dfs2(next_node, components);
    }
  };

  vector<int> component;
  vector<vector<int>> components;
  while (!s.empty()) {
    int node = s.back();
    s.pop_back();

    component.clear();
    dfs2(node, component);
    if (!component.empty()) {
      components.push_back(component);
    }
  }

  // cout << "components: " << endl;
  // for (vector<int>& c : components) {
  //   for (int node : c) cout << node << " ";
  //   cout << endl;
  // }

  int scc_size = components.size();
  vector<int> node_scc(n+1);
  vector<i64> b(scc_size);
  for (int i = 0; i < scc_size; ++i) {
    for (int node : components[i]) {
      node_scc[node] = i;
      b[i] += a[node];
    }
  }

  // cout << "new values: " << endl;
  // for (int i = 0; i < scc_size; ++i) {
  //   cout << b[i] << " ";
  // }
  // cout << endl;

  vector<vector<int>> adj2(scc_size);
  for (vector<int>& sc : components) {
    for (int node : sc) {
      int c1 = node_scc[node];
      for (int next_node : adj[node]) {
        int c2 = node_scc[next_node];
        if (c1 != c2) {
          adj2[c1].push_back(c2);
          // cout << c1 << " -> " << c2 << endl;
        }
      }
    }
  }

  vector<pair<int,i64>> memo(scc_size, {0, 0});
  function<pair<int,i64>(int)> dfs3 = [&](int c) -> pair<int,i64> {
    if (memo[c].first) {
      return memo[c];
    }

    int size = components[c].size();
    memo[c] = {size, -b[c]};
    for (int c2 : adj2[c]) {
      auto [size2, value] = dfs3(c2);
      memo[c] = max(memo[c], {size2 + size, value-b[c]});
    }
    return memo[c];
  };

  pair<int,i64> ans = {0, 0};
  for (int c = 0; c < scc_size; ++c) {
    ans = max(ans, dfs3(c));
  }

  cout << ans.first << " " << -ans.second << endl;
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
