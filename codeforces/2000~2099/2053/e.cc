#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dist_to_leaf(n+1, -1);
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1) {
      q.push(i);
      dist_to_leaf[i] = 0;
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();

      for (int next_node : adj[node]) {
        if (dist_to_leaf[next_node] >= 0) {
          continue;
        }
        dist_to_leaf[next_node] = dist_to_leaf[node]+1;
        q.push(next_node);
      }
    }
  }

  i64 leafs = 0;
  for (int node = 1; node <= n; ++node) {
    leafs += (dist_to_leaf[node] == 0);
  }
  i64 non_leafs = n -leafs;
  i64 ans = leafs * non_leafs;

  vector<int> possible_p_count(n+1);
  function<void(int,int)> count_p = [&](int node, int parent) {
    if (dist_to_leaf[node] >= 2) {
      possible_p_count[node] += 1;
    }
    for (int next_node : adj[node]) {
      if (next_node == parent) {
        continue;
      }
      count_p(next_node, node);
      possible_p_count[node] += possible_p_count[next_node];
    }
  };

  count_p(1, 0);
  int total_possible_p = possible_p_count[1];
  function<void(int,int)> dfs = [&](int node, int parent) {
    if (parent > 0 && dist_to_leaf[node] == 1 && dist_to_leaf[parent] > 0) {
      ans += possible_p_count[node];
    }

    for (int next_node : adj[node]) {
      if (next_node == parent) {
        continue;
      }

      if (dist_to_leaf[node] == 1 && dist_to_leaf[next_node] > 0) {
        int under = possible_p_count[next_node];
        int rest = total_possible_p - under;
        // cout << "q=" << next_node << ", q-1 = " << node << endl;
        ans += rest;
      }

      dfs(next_node, node);
    }
  };

  dfs(1, 0);

  cout << ans << endl;
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
