#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, int node, stack<int>& s, vector<bool>& visited) {
  if (!visited[node]) {
    visited[node] = true;
    for (int next : adj[node]) {
      dfs(adj, next, s, visited);
    }
    s.push(node);
  }
}

void dfs2(vector<vector<int>>& reverse, int node, vector<int>& component, vector<bool>& visited) {
  if (visited[node]) {
    visited[node] = false;
    component.push_back(node);
    for (int next : reverse[node]) {
      dfs2(reverse, next, component, visited);
    }
  }
}

vector<vector<int>> korasaju(vector<vector<int>>& adj) {
  int n = adj.size();
  vector<bool> visited(n, false);
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    dfs(adj, i, s, visited);
  }

  vector<vector<int>> reverse(n);
  for (int i = 0; i < n; ++i) {
    for (int next : adj[i]) {
      reverse[next].push_back(i);
    }
  }

  vector<vector<int>> components;
  while (s.size() > 0) {
    int node = s.top();
    vector<int> component;
    dfs2(reverse, node, component, visited);
    if (component.size() > 0) components.push_back(component);
    s.pop();
  }

  return components;
}

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<vector<int>> adj(n);
    int e = 0;
    cin >> e;
    for (int i = 0; i < e; ++i) {
      int s = 0, e = 0;
      cin >> s >> e;
      adj[s].push_back(e);
    }

    vector<vector<int>> components = korasaju(adj);
    for (vector<int> component : components) {
      for (int node : component) cout << node << " ";
      cout << endl;
    }
  }
  return 0;
}
