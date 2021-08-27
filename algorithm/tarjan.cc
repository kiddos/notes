#include <bits/stdc++.h>

using namespace std;

class DirectedGraph {
 public:
  DirectedGraph(int n) : adj_(n) {}

  void add_edge(int from, int to) {
    adj_[from].push_back(to);
  }

  vector<int> tarjan() {
    int n = adj_.size();
    vector<int> lowlink(n);
    vector<int> ids(n, -1);
    vector<bool> on_stack(n);
    stack<int> st;
    int component_count = 0;
    int id = 0;

    function<void(int)> dfs = [&](int node) {
      st.push(node);
      on_stack[node] = true;
      ids[node] = lowlink[node] = id++;

      for (int neighbor : adj_[node]) {
        if (ids[neighbor] == -1) dfs(neighbor);
        if (on_stack[neighbor])
          lowlink[node] = min(lowlink[node], lowlink[neighbor]);
      }

      if (ids[node] == lowlink[node]) {
        while (!st.empty()) {
          int stack_node = st.top();
          st.pop();
          on_stack[stack_node] = false;
          lowlink[stack_node] = node;
          if (stack_node == node) break;
        }
        component_count++;
      }
    };

    for (int node = 0; node < n; ++node) {
      if (ids[node] == -1) {
        dfs(node);
      }
    }
    return lowlink;
  }

 private:
  vector<vector<int>> adj_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  DirectedGraph graph(8);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 0);

  graph.add_edge(3, 4);
  graph.add_edge(3, 7);
  graph.add_edge(4, 5);
  graph.add_edge(5, 6);
  graph.add_edge(5, 0);
  graph.add_edge(6, 4);
  graph.add_edge(6, 2);
  graph.add_edge(6, 0);

  graph.add_edge(7, 3);
  graph.add_edge(7, 5);

  vector<int> lowlink = graph.tarjan();
  unordered_map<int, vector<int>> components;
  for (int node = 0; node < lowlink.size(); ++node) {
    components[lowlink[node]].push_back(node);
  }
  for (auto component : components) {
    cout << "component: " << component.first << " : ";
    for (int node : component.second) {
      cout << node << ", ";
    }
    cout << endl;
  }
  return 0;
}
