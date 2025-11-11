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

  vector<int> d1(n+1);
  compute_dists(compute_dists, 1, 1, d1);

  int end_node = max_element(d1.begin(), d1.end()) - d1.begin();
  vector<int> d2(n+1);
  compute_dists(compute_dists, end_node, end_node, d2);

  int ans = *max_element(d2.begin(), d2.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
