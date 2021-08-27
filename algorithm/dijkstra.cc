#include <bits/stdc++.h>

using namespace std;

class Graph {
 public:
  Graph(int n) : adj_(n) {}

  void add_edge(int u, int v, int cost) {
    adj_[u].push_back(make_pair(v, cost));
  }

  vector<int> dijkstra(int from) {
    int n = adj_.size();
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n, numeric_limits<int>::max());
    dist[from] = 0;
    pq.push({from, 0});
    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      for (auto neighbor : adj_[node.first]) {
        int new_dist = node.second + neighbor.second;
        if (new_dist < dist[neighbor.first]) {
          dist[neighbor.first] = new_dist;
          pq.push({neighbor.first, new_dist});
        }
      }
    }
    return dist;
  }

 private:
  vector<vector<pair<int, int>>> adj_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int n = 6;
  Graph graph(n);
  graph.add_edge(0, 1, 5);
  graph.add_edge(0, 2, 1);
  graph.add_edge(1, 3, 3);
  graph.add_edge(1, 4, 20);
  graph.add_edge(1, 2, 2);
  graph.add_edge(2, 1, 3);
  graph.add_edge(2, 4, 12);
  graph.add_edge(3, 2, 3);
  graph.add_edge(3, 4, 2);
  graph.add_edge(3, 5, 6);
  graph.add_edge(4, 5, 1);

  for (int from = 0; from < n; ++from) {
    vector<int> dist = graph.dijkstra(from);
    for (int to = 0; to < dist.size(); ++to) {
      cout << "distance from " << from << " to " << to << " = ";
      if (dist[to] == numeric_limits<int>::max()) cout << "INFINITE";
      else cout << dist[to];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
