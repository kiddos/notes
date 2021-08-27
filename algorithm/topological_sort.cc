#include <bits/stdc++.h>

using namespace std;

class Graph {
 public:
  Graph() {}

  void add_edge(char u, char v) {
    adj_[u].push_back(v);
    nodes_.insert(u);
    nodes_.insert(v);
  }

  vector<char> top_sort() {
    vector<char> order;
    unordered_set<char> visited;
    function<void(char)> dfs = [&](char node) {
      if (visited.count(node)) return;
      visited.insert(node);
      for (char neighbor : adj_[node]) {
        dfs(neighbor);
      }
      order.push_back(node);
    };
    for (char node : nodes_) {
      dfs(node);
    }
    reverse(order.begin(), order.end());
    return order;
  }

 private:
  unordered_set<char> nodes_;
  unordered_map<char, vector<char>> adj_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Graph graph;
  graph.add_edge('A', 'D');
  graph.add_edge('B', 'D');
  graph.add_edge('C', 'A');
  graph.add_edge('C', 'B');
  graph.add_edge('D', 'H');
  graph.add_edge('D', 'G');
  graph.add_edge('E', 'A');
  graph.add_edge('E', 'D');
  graph.add_edge('E', 'F');
  graph.add_edge('F', 'K');
  graph.add_edge('F', 'J');
  graph.add_edge('G', 'I');
  graph.add_edge('H', 'I');
  graph.add_edge('H', 'J');
  graph.add_edge('I', 'L');
  graph.add_edge('J', 'M');
  graph.add_edge('J', 'L');
  graph.add_edge('K', 'J');

  vector<char> order = graph.top_sort();
  for (char o : order) cout << o << " ";
  cout << endl;
  return 0;
}
