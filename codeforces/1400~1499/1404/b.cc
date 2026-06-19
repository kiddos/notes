#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  i64 da = 0, db = 0;
  cin >> n >> a >> b >> da >> db;
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

  auto compute_dist = [&](const auto& self, int node, int p, vector<int>& dists) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dists[next_node] = dists[node]+1;
      self(self, next_node, node, dists);
    }
  };

  vector<int> d1(n+1);
  compute_dist(compute_dist, a, a, d1);

  if (d1[b] <= da) {
    cout << "Alice" << endl;
    return;
  }

  int node1 = max_element(d1.begin(), d1.end()) -  d1.begin();
  vector<int> d2(n+1);
  compute_dist(compute_dist, node1, node1, d2);

  int node2 = max_element(d2.begin(), d2.end()) - d2.begin();
  vector<int> d3(n+1);
  compute_dist(compute_dist, node2, node2, d3);

  i64 max_dist = *max_element(d3.begin(), d3.end());
  if (max_dist > da * 2 && db > da * 2) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
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
