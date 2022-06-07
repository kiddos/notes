#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int u, v, c;
};

class EdmondKarp {
 public:
  int max_flow(int s, int t, int n, vector<Edge>& edges) {
    vector<vector<int>> adj(n);
    vector<vector<int>> capacity(n, vector<int>(n));
    for (auto [u, v, c] : edges) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      capacity[u][v] = c;
    }

    vector<int> parent(n);
    auto bfs = [&](int s, int t) -> int {
      fill(parent.begin(), parent.end(), -1);
      parent[s] = -2;
      queue<pair<int,int>> q;
      q.push({s, numeric_limits<int>::max()});

      while (!q.empty()) {
        auto [node, flow] = q.front();
        q.pop();
        for (int next_node : adj[node]) {
          if (parent[next_node] == -1 && capacity[node][next_node]) {
            parent[next_node] = node;
            int new_flow = min(flow, capacity[node][next_node]);
            if (next_node == t) {
              return new_flow;
            }
            q.push({next_node, new_flow});
          }
        }
      }
      return 0;
    };

    int flow = 0;
    int new_flow = 0;
    while ((new_flow = bfs(s, t))) {
      flow += new_flow;
      int node = t;
      while (node != s) {
        int p = parent[node];
        capacity[p][node] -= new_flow;
        capacity[node][p] += new_flow;
        node = p;
      }
    }

    cout << "capacity: " << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n ; ++j) {
        cout << capacity[i][j] << " ";
      }
      cout << endl;
    }
    return flow;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 11;
  vector<Edge> edges;
  edges.push_back(Edge{0, 1, 7});
  edges.push_back(Edge{0, 2, 2});
  edges.push_back(Edge{0, 3, 1});
  edges.push_back(Edge{1, 4, 2});
  edges.push_back(Edge{1, 5, 4});
  edges.push_back(Edge{2, 5, 5});
  edges.push_back(Edge{2, 6, 6});
  edges.push_back(Edge{3, 4, 4});
  edges.push_back(Edge{3, 8, 8});
  edges.push_back(Edge{4, 7, 7});
  edges.push_back(Edge{4, 8, 1});
  edges.push_back(Edge{5, 7, 3});
  edges.push_back(Edge{5, 9, 3});
  edges.push_back(Edge{6, 9, 3});
  edges.push_back(Edge{7, 10, 1});
  edges.push_back(Edge{8, 10, 2});
  edges.push_back(Edge{9, 10, 4});

  int max_flow = EdmondKarp().max_flow(0, 10, n, edges);
  cout << "max flow: " << max_flow << endl;
  return 0;
}
