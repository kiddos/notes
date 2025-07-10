#include <bits/stdc++.h>

using namespace std;

vector<int> articulation_points(vector<vector<int>>& adj) {
  int n = adj.size();
  int id = 0;
  vector<int> lowlink(n), ids(n, -1);
  vector<bool> visited(n);
  vector<bool> is_art(n);
  int out_edge_count = 0;

  auto dfs = [&](const auto& self, int root, int node, int parent) -> void {
    if (parent == root) out_edge_count++;
    visited[node] = true;
    lowlink[node] = ids[node] = ++id;
    for (int neighbor : adj[node]) {
      if (parent == neighbor) continue;
      if (!visited[neighbor]) {
        self(self, root, neighbor, node);
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
      dfs(dfs, node, node, -1);
      is_art[node] = out_edge_count > 1;
    }
  }

  vector<int> p;
  for (int node = 0; node < n; ++node) {
    if (is_art[node]) {
      p.push_back(node);
    }
  }
  return p;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<pair<int,int>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(1, 2);
  edges.emplace_back(2, 0);
  edges.emplace_back(2, 3);
  edges.emplace_back(2, 5);
  edges.emplace_back(3, 4);
  edges.emplace_back(5, 6);
  edges.emplace_back(6, 7);
  edges.emplace_back(7, 8);
  edges.emplace_back(8, 5);

  int n = 9;
  vector<vector<int>> adj(n);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> ap = articulation_points(adj);
  cout << "articulation points: " << endl;
  for (int p : ap) {
    cout << p << " ";
  }
  cout << endl;
  return 0;
}
