#include <bits/stdc++.h>

using namespace std;

class Graph {
 public:
  Graph(int n) : adj_(n) {}

  void add_edge(int u, int v, int cost) {
    adj_[u].push_back({v, cost});
    adj_[v].push_back({u, cost});
  }

  int prim(int start = 0) {
    int n = adj_.size(), count = 0, cost = 0;
    priority_queue<array<int, 3>> pq;
    vector<bool> visited(n);
    vector<int> parent(n, -1);

    pq.push({0, start, -1});
    while (!pq.empty() && count < n) {
      auto [c, u, p] = pq.top();
      pq.pop();
      if (visited[u]) continue;
      visited[u] = true;
      cost -= c;
      count++;
      parent[u] = p;
      for (auto& edge: adj_[u]) {
        if (!visited[edge.first]) {
          pq.push({-edge.second, edge.first, u});
        }
      }
    }
    parent_ = parent;
    return cost;
  }

  vector<int> parent() const { return parent_; }

 private:
  vector<int> parent_;
  vector<vector<pair<int, int>>> adj_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Graph graph(8);
  graph.add_edge(0, 1, 10);
  graph.add_edge(0, 3, 4);
  graph.add_edge(0, 2, 1);
  graph.add_edge(1, 2, 3);
  graph.add_edge(1, 4, 0);
  graph.add_edge(2, 5, 8);
  graph.add_edge(2, 3, 2);
  graph.add_edge(3, 5, 2);
  graph.add_edge(3, 6, 7);
  graph.add_edge(4, 5, 1);
  graph.add_edge(4, 7, 8);
  graph.add_edge(5, 7, 9);
  graph.add_edge(5, 6, 6);
  graph.add_edge(6, 7, 12);

  int cost = graph.prim();
  vector<int> parent = graph.parent();
  cout << "minimum cost: " << cost << endl;
  for (int node = 0; node < parent.size(); ++node) {
    cout << node << "'s parent = " << parent[node] << endl;
  }
  cout << endl;
  return 0;
}
