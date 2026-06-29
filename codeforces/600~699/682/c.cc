#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<int,i64>>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    int p = 0, c = 0;
    cin >> p >> c;
    adj[p].push_back({i, c});
  }

  vector<i64> max_dist(n+1);
  auto dfs1 = [&](const auto& self, int node) -> void {
    for (auto [next_node, c] : adj[node]) {
      max_dist[next_node] = max(max_dist[node], 0LL) + c;
      self(self, next_node);
    }
  };

  dfs1(dfs1, 1);

  // for (int i = 1; i <= n; ++i) {
  //   cout << max_dist[i] << " ";
  // }
  // cout << endl;

  vector<int> subtree_size(n+1, 1);
  auto dfs2 = [&](const auto& self, int node) -> void {
    for (auto [next_node, c] : adj[node]) {
      self(self, next_node);
      subtree_size[node] += subtree_size[next_node];
    }
  };

  dfs2(dfs2, 1);

  int ans = 0;
  auto dfs3 = [&](const auto& self, int node) -> void {
    if (max_dist[node] > a[node]) {
      // cout << "remove node =" << node << endl;
      ans += subtree_size[node];
      return;
    }
    for (auto [next_node, c] : adj[node]) {
      self(self, next_node);
    }
  };

  dfs3(dfs3, 1);

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
