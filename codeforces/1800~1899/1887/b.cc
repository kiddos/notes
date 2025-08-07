#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;

  vector<vector<pair<int,int>>> roads;
  for (int i = 0; i < t; ++i) {
    int m = 0;
    cin >> m;
    vector<pair<int,int>> edges;
    for (int j = 0; j < m; ++j) {
      int u = 0, v = 0;
      cin >> u >> v;
      edges.emplace_back(u, v);
    }
    roads.push_back(edges);
  }

  int k = 0;
  cin >> k;
  vector<int> a(k+1);
  for (int i = 1; i <= k; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 0; i < t; ++i) {
    for (auto [u, v] : roads[i]) {
      adj[u].push_back({v, i+1});
      adj[v].push_back({u, i+1});
    }
  }

  vector<vector<int>> a_indices(t+1);
  for (int i = 1; i <= k; ++i) {
    a_indices[a[i]].push_back(i);
  }

  constexpr int inf = numeric_limits<int>::max();
  vector<int> dist(n+1, inf);
  dist[1] = 0;
  priority_queue<array<int,2>, vector<array<int,2>>, greater<>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d1, node] = pq.top();
    pq.pop();
    if (node == n) {
      break;
    }

    for (auto [next_node, ai] : adj[node]) {
      vector<int>& indices = a_indices[ai];
      auto it = lower_bound(indices.begin(), indices.end(), d1+1);
      if (it == indices.end()) {
        continue;
      }
      int d2 = *it;
      if (d2 < dist[next_node]) {
        dist[next_node] = d2;
        pq.push({d2, next_node});
      }
    }
  }

  if (dist[n] == inf) {
    cout << "-1" << endl;
  } else {
    cout << dist[n] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
