#include <bits/stdc++.h>

using namespace std;

class Graph {
 public:
  Graph(int n) : adj_(n) {}

  void add_edge(int u, int v) {
    adj_[u].push_back(v);
    adj_[v].push_back(u);
  }

  vector<int> articulation_points() {
    int n = adj_.size(), id = 0;
    vector<int> lowlink(n), ids(n, -1);
    vector<bool> visited(n);
    vector<bool> is_art(n);
    int out_edge_count = 0;

    function<void(int, int, int)> dfs = [&](int root, int node, int parent) {
      if (parent == root) out_edge_count++;
      visited[node] = true;
      lowlink[node] = ids[node] = ++id;
      for (int neighbor : adj_[node]) {
        if (parent == neighbor) continue;
        if (!visited[neighbor]) {
          dfs(root, neighbor, node);
          lowlink[node] = min(lowlink[node], lowlink[neighbor]);
          if (ids[node] <= lowlink[neighbor]) is_art[node] = true;
        } else {
          lowlink[node] = min(lowlink[node], lowlink[neighbor]);
        }
      }
    };

    for (int node = 0; node < n; ++node) {
      if (!visited[node]) {
        out_edge_count = 0;
        dfs(node, node, -1);
        is_art[node] = out_edge_count > 1;
      }
    }

    vector<int> p;
    for (int node = 0; node < n; ++node) if (is_art[node]) p.push_back(node);
    return p;
  }

 private:
  vector<vector<int>> adj_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Graph graph(9);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 0);
  graph.add_edge(2, 3);
  graph.add_edge(2, 5);
  graph.add_edge(3, 4);
  graph.add_edge(5, 6);
  graph.add_edge(6, 7);
  graph.add_edge(7, 8);
  graph.add_edge(8, 5);

  vector<int> articulation_points = graph.articulation_points();
  cout << "articulation points: " << endl;
  for (int p : articulation_points) {
    cout << p << " ";
  }
  cout << endl;
  return 0;
}
