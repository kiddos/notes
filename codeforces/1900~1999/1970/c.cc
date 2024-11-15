#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
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

  vector<int> dist(n+1);
  function<void(int,int)> compute_dist = [&](int node, int p) {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      dist[next_node] = dist[node] + 1;
      compute_dist(next_node, node);
    }
  };

  for (int i = 0; i < t; ++i) {
    int u = 0;
    cin >> u;
    compute_dist(u, u);
  }

  vector<int> leafs;
  for (int node = 1; node <= n; ++node) {
    if (adj[node].size() == 1) {
      leafs.push_back(node);
    }
  }
  assert(leafs.size() == 2);

  int d1 = dist[leafs[0]], d2 = dist[leafs[1]];
  if (d1 % 2 == 1 || d2 % 2 == 1) {
    cout << "Ron" << endl;
  } else {
    cout << "Hermione" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
