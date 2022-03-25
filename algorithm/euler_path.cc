#include <bits/stdc++.h>

using namespace std;

bool is_eulerian(int n, vector<vector<int>>& edges) {
  vector<int> indegree(n), outdegree(n);
  vector<vector<int>> adj(n);
  for (vector<int>& edge : edges) {
    int u = edge[0], v = edge[1];
    adj[u].push_back(v);
    indegree[v]++;
    outdegree[u]++;
  }

  int start = 0, end = 0;
  for (int node = 0; node < n; ++node) {
    if (outdegree[node] - indegree[node] == 1) {
      start++;
    } else if (indegree[node] - outdegree[node] == 1) {
      end++;
    } else if (indegree[node] != outdegree[node]) {
      return false;
    }
  }
  return (start == 0 && end == 0) || (start == 1 || end == 1);
}

vector<int> euler_path(int n, vector<vector<int>>& edges) {
  vector<int> indegree(n), outdegree(n);
  vector<vector<int>> adj(n);
  for (vector<int>& edge : edges) {
    int u = edge[0], v = edge[1];
    adj[u].push_back(v);
    indegree[v]++;
    outdegree[u]++;
  }

  vector<int> path;
  function<void(int)> dfs = [&](int node) {
    while (outdegree[node]) {
      outdegree[node]--;
      dfs(adj[node][outdegree[node]]);
    }
    path.push_back(node);
  };

  int start_node = 0;
  for (int node = 0; node < n; ++node) {
    if (outdegree[node] - indegree[node] == 1) {
      start_node = node;
      break;
    }
  }

  dfs(start_node);
  reverse(path.begin(), path.end());
  return path;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int n = 7;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 1}, {1, 3}, {3, 4}, {4, 5}, {5, 6}};
  cout << is_eulerian(n, edges) << endl;

  vector<int> path = euler_path(n, edges);
  for (int ele : path) cout << ele << ' ';
  cout << endl;

  return 0;
}
