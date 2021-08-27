#include <bits/stdc++.h>

using namespace std;

class Graph {
 public:
  Graph(int n) : adj_(n) {}

  void add_edge(int from, int to) {
    adj_[from].push_back(to);
    adj_[to].push_back(from);
  }

  vector<vector<int>> find_bridge() {
    int n = adj_.size();
    vector<int> ids(n, -1);
    vector<int> lowlink(n);
    vector<bool> visited(n);
    vector<vector<int>> bridges;
    int id = 0;

    function<void(int, int)> dfs = [&](int node, int parent) {
      visited[node] = true;
      ids[node] = lowlink[node] = ++id;
      for (int neighbor : adj_[node]) {
        if (neighbor == parent) continue;
        if (!visited[neighbor]) {
          dfs(neighbor, node);
          lowlink[node] = min(lowlink[node], lowlink[neighbor]);
          if (ids[node] < lowlink[neighbor]) {
            bridges.push_back({node, neighbor});
          }
        } else {
          lowlink[node] = min(lowlink[node], lowlink[neighbor]);
        }
      }
    };

    for (int node = 0; node < n; ++node) {
      if (ids[node] == -1) {
        dfs(node, -1);
      }
    }
    return bridges;
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

  auto bridges = graph.find_bridge();
  for (vector<int>& b : bridges) {
    cout << b[0] << ", " << b[1] << endl;
  }
  return 0;
}
