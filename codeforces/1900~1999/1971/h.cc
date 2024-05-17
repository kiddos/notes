#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> g(3, vector<int>(n));
  for (int r = 0; r < 3; ++r) {
    for (int i = 0; i < n; ++i) {
      cin >> g[r][i];
    }
  }

  map<int, int> to_index;
  int idx = 0;
  for (int r = 0; r < 3; ++r) {
    for (int i = 0; i < n; ++i) {
      if (!to_index.count(g[r][i])) {
        to_index[g[r][i]] = idx++;
      }
      if (!to_index.count(-g[r][i])) {
        to_index[-g[r][i]] = idx++;
      }
    }
  }

  auto clean_up = [&](vector<vector<int>>& adj) {
    for (vector<int>& list : adj) {
      sort(list.begin(), list.end());
      list.resize(unique(list.begin(), list.end()) - list.begin());
    }
  };

  int m = to_index.size();
  vector<vector<int>> adj(m);
  auto make_2sat_clause = [&](int a, int b) {
    adj[to_index[-a]].push_back(to_index[b]);
    adj[to_index[-b]].push_back(to_index[a]);
  };

  for (int i = 0; i < n; ++i) {
    make_2sat_clause(g[0][i], g[1][i]);
    make_2sat_clause(g[1][i], g[2][i]);
    make_2sat_clause(g[2][i], g[0][i]);
  }

  clean_up(adj);

  vector<vector<int>> rev_adj(m);
  for (int node = 0; node < m; ++node) {
    for (int next_node : adj[node]) {
      rev_adj[next_node].push_back(node);
    }
  }

  clean_up(rev_adj);

  vector<bool> visited(m);
  vector<int> ordering;
  function<void(int)> dfs1 = [&](int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      dfs1(next_node);
    }
    ordering.push_back(node);
  };

  for (int node = 0; node < m; ++node) {
    if (!visited[node]) {
      dfs1(node);
    }
  }

  reverse(ordering.begin(), ordering.end());

  vector<int> component(m, -1);
  function<void(int,int)> dfs2 = [&](int node, int c) {
    if (component[node] >= 0) {
      return;
    }
    component[node] = c;
    for (int next_node : rev_adj[node]) {
      dfs2(next_node, c);
    }
  };

  int c = 1;
  for (int node : ordering) {
    if (component[node] == -1) {
      dfs2(node, c++);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!to_index.count(i) || !to_index.count(-i)) {
      continue;
    }
    int node1 = to_index[i], node2 = to_index[-i];

    if (component[node1] == component[node2]) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
