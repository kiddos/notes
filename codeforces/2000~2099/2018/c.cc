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

  vector<int> degree(n+1);
  vector<vector<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  vector<int> depth(n+1);
  vector<bool> is_leaf(n+1);
  function<void(int,int)> dfs = [&](int node, int p) {
    is_leaf[node] = true;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      is_leaf[node] = false;
      depth[next_node] = depth[node] + 1;
      dfs(next_node, node);
    }
  };

  dfs(1, 0);

  int max_depth = *max_element(depth.begin(), depth.end());

  vector<vector<int>> leafs(max_depth+2);
  vector<int> node_count(max_depth+2);
  for (int node = 1; node <= n; ++node) {
    if (is_leaf[node]) {
      leafs[depth[node]].push_back(node);
    }
    node_count[depth[node]]++;
  }

  int total_removed = 0;
  function<void(int)> remove_leaf = [&](int node) {
    queue<int> q;
    q.push(node);
    // cout << "start to remove: " << node << endl;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        total_removed++;

        int x = q.front();
        // cout << "remove: " << x << endl;
        q.pop();
        for (int other_node : adj[x]) {
          if (--degree[other_node] == 1 && other_node != 1) {
            q.push(other_node);
          }
        }
      }
    }
  };

  vector<int> leaf_to_remove(max_depth+2);
  for (int d = 1; d <= max_depth; ++d) {
    for (int leaf : leafs[d]) {
      remove_leaf(leaf);
    }
    leaf_to_remove[d] = total_removed;
  }

  // cout << "leaf to remove: ";
  // for (int d = 0; d <= max_depth+1; ++d) {
  //   cout << leaf_to_remove[d] << " ";
  // }
  // cout << endl;
  // cout << "node count: ";
  // for (int d = 0; d <= max_depth+1; ++d) {
  //   cout << node_count[d] << " ";
  // }
  // cout << endl;

  vector<int> prefix = leaf_to_remove;
  vector<int> suffix = node_count;
  for (int d = max_depth; d >= 1; --d) {
    suffix[d] += suffix[d+1];
  }

  int ans = n;
  for (int d = 1; d <= max_depth; ++d) {
    // for depth = d
    // trim all leaf node with depth < d
    // and remove all node with depth > d
    int remove = prefix[d-1] + suffix[d+1];
    ans = min(ans, remove);
  }
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
