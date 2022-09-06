#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int u, v;
  int weight;
};

bool bellman_ford(int n, vector<Edge>& edges, int source) {
  vector<vector<pair<int,int>>> adj(n);
  for (auto& [u, v, weight] : edges) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  const int INF = numeric_limits<int>::max();
  vector<int> dist(n, INF);
  dist[source] = 0;

  for (int i = 0; i < n-1; ++i) {
    for (auto& [u, v, w] : edges) {
      if (dist[u] < INF && dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
      }
    }
  }

  for (auto& [u, v, w] : edges) {
    if (dist[u] < INF && dist[u] + w < dist[v]) {
      return true;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int N = 5;
  vector<Edge> edges;
  edges.push_back(Edge{0, 1, -1});
  edges.push_back(Edge{0, 2, 4});
  edges.push_back(Edge{1, 2, 3});
  edges.push_back(Edge{1, 3, 2});
  edges.push_back(Edge{1, 4, 2});
  edges.push_back(Edge{3, 2, 5});
  edges.push_back(Edge{3, 1, 1});
  edges.push_back(Edge{4, 3, -3});

  assert(!bellman_ford(N, edges, 0));
  return 0;
}
