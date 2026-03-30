#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<i64> sum_a(n+1);
  vector<i64> costs(n+1);
  vector<int> children_count(n+1);
  vector<int> max_h(n+1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void {
    sum_a[node] += a[node];
    max_h[node] = 1;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      sum_a[node] += sum_a[next_node];
      costs[node] += costs[next_node] + sum_a[next_node];
      children_count[node]++;
      max_h[node] = max(max_h[node], max_h[next_node]+1);
    }
  };

  dfs1(dfs1, 1, 0);

  // for (int i = 1; i <= n; ++i) {
  //   cout << costs[i] << " ";
  // }
  // cout << endl;

  vector<i64> best_add(n+1);
  auto dfs2 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }

    if (children_count[node] > 1) {
      multiset<int> heights;
      for (int next_node : adj[node]) {
        if (next_node == p) {
          continue;
        }
        heights.insert(max_h[next_node]);
      }
      for (int next_node : adj[node]) {
        if (next_node == p) {
          continue;
        }
        heights.erase(heights.find(max_h[next_node]));
        int other_heights = *heights.rbegin();
        best_add[node] = max(best_add[node], sum_a[next_node] * other_heights);
        heights.insert(max_h[next_node]);
      }
    }
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      best_add[node] = max(best_add[node], best_add[next_node]);
    }
  };

  dfs2(dfs2, 1, 0);

  // for (int i = 1; i <= n; ++i) {
  //   cout << best_add[i] << " ";
  // }
  // cout << endl;

  vector<i64> ans(n+1);
  for (int i = 1; i <= n; ++i) {
    ans[i] = costs[i] + best_add[i];
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
