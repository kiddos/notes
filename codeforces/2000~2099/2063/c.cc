#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<int> degree(n+1);
  vector<unordered_set<int>> adj(n+1);
  for (auto [u, v] : edges) {
    degree[u]++;
    degree[v]++;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  multiset<int> d;
  for (int node = 1; node <= n; ++node) {
    d.insert(degree[node]);
  }

  int ans = 0;
  function<void(int,int)> dfs = [&](int node, int p) {
    for (int next_node : adj[node]) {
      int total = degree[next_node] + degree[node] - 2;
      ans = max(ans, total);
    }
    d.erase(d.find(degree[node]));
    for (int next_node : adj[node]) {
      d.erase(d.find(degree[next_node]));
    }
    if (!d.empty()) {
      ans = max(ans, degree[node] + *d.rbegin() - 1);
    }

    d.insert(degree[node]);
    for (int next_node : adj[node]) {
      d.insert(degree[next_node]);
    }

    for (int next_node : adj[node]) {
      if (p == next_node) {
        continue;
      }
      dfs(next_node, node);
    }
  };

  dfs(1, 0);

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
