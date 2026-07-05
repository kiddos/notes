#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, s = 0, t = 0;
  cin >> n >> m >> s >> t;
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

  auto compute_dist = [&](vector<int>& dists, int source) -> void {
    queue<int> q;
    q.push(source);
    dists[source] = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();
        for (int next_node : adj[node]) {
          if (dists[next_node] >= 0) {
            continue;
          }
          dists[next_node] = dists[node] + 1;
          q.push(next_node);
        }
      }
    }
  };

  vector<int> source_dists(n+1, -1);
  compute_dist(source_dists, s);
  vector<int> target_dists(n+1, -1);
  compute_dist(target_dists, t);

  set<pair<int,int>> edge_set(edges.begin(), edges.end());

  int ans = 0;
  int min_dist = source_dists[t];
  for (int node1 = 1; node1 <= n; ++node1) {
    for (int node2 = node1+1; node2 <= n; ++node2) {
      if (edge_set.count({node1, node2}) || edge_set.count({node2, node1})) {
        continue;
      }
      int new_dist = min(source_dists[node1] + target_dists[node2], source_dists[node2] + target_dists[node1]) + 1;
      if (new_dist >= min_dist) {
        // cout << "add " << node1 << "-" << node2 << endl;
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
