#include <bits/stdc++.h>

using namespace std;

constexpr int inf = numeric_limits<int>::max();

vector<int> dijkstra(vector<vector<pair<int,int>>> adj, int from) {
  int n = adj.size();
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
  vector<int> dists(n, inf);
  dists[from] = 0;
  pq.push({0, from});
  while (!pq.empty()) {
    auto [dist, node]  = pq.top();
    pq.pop();
    for (auto [next_node, edge_weight] : adj[node]) {
      int new_dist = dist + edge_weight;
      if (new_dist < dists[next_node]) {
        dists[next_node] = new_dist;
        pq.push({new_dist, next_node});
      }
    }
  }
  return dists;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int n = 6;
  vector<array<int,3>> edges;
  edges.push_back({0, 1, 5});
  edges.push_back({0, 2, 1});
  edges.push_back({1, 3, 3});
  edges.push_back({1, 4, 20});
  edges.push_back({1, 2, 2});
  edges.push_back({2, 1, 3});
  edges.push_back({2, 4, 12});
  edges.push_back({3, 2, 3});
  edges.push_back({3, 4, 2});
  edges.push_back({3, 5, 6});
  edges.push_back({4, 5, 1});

  vector<vector<pair<int,int>>> adj(n);
  for (auto [u, v, cost] : edges) {
    adj[u].push_back({v, cost});
    adj[v].push_back({u, cost});
  }

  for (int from = 0; from < n; ++from) {
    vector<int> dist = dijkstra(adj, from);
    for (int to = 0; to < n; ++to) {
      cout << "distance from " << from << " to " << to << " = ";
      if (dist[to] == inf) cout << "INFINITE";
      else cout << dist[to];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
