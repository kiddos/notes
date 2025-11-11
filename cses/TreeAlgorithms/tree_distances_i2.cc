#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto compute_dists = [&](const auto& self, int node, int p, vector<int>& dists) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dists[next_node] = dists[node] + 1;
      self(self, next_node, node, dists);
    }
  };

  vector<int> d0(n+1);
  compute_dists(compute_dists, 1, 1, d0);

  int node_a = max_element(d0.begin(), d0.end()) - d0.begin();
  vector<int> d1(n+1);
  compute_dists(compute_dists, node_a, node_a, d1);
  int node_b = max_element(d1.begin(), d1.end()) - d1.begin();
  vector<int> d2(n+1);
  compute_dists(compute_dists, node_b, node_b, d2);

  vector<int> ans(n+1);
  auto dfs2 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }
    ans[node] = max(d1[node], d2[node]);
  };

  dfs2(dfs2, 1, 1);

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
