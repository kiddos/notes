#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, w = 0;
    cin >> a >> b >> w;
    edges.push_back({a, b, w});
  }
  vector<vector<pair<int,int>>> adj(n+1);
  for (auto [a, b, w] : edges) {
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  priority_queue<pair<i64,int>, vector<pair<i64,int>>, greater<>> pq;
  pq.push({0, 1});
  constexpr i64 inf = 1e18;
  vector<i64> dists(n+1, inf);
  dists[1] = 0;
  vector<int> prev(n+1, -1);

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    for (auto [next_node, w] : adj[node]) {
      i64 d2 = d + w;
      if (d2 < dists[next_node]) {
        dists[next_node] = d2;
        pq.push({d2, next_node});
        prev[next_node] = node;
      }
    }
  }

  if (dists[n] == inf) {
    cout << "-1" << endl;
    return;
  }

  vector<int> path;
  int current = n;
  while (current > 0) {
    path.push_back(current);
    current = prev[current];
  }
  reverse(path.begin(), path.end());
  for (int node : path) {
    cout << node << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
