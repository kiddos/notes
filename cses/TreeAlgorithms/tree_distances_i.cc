#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> max_dist(n+1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      max_dist[node] = max(max_dist[node], max_dist[next_node] + 1);
    }
  };

  dfs1(dfs1, 1, 1);

  vector<int> ans(n+1);

  auto dfs2 = [&](const auto& self, int node, int p, int from_parent) -> void {
    multiset<int> s = {from_parent};
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      s.insert(max_dist[next_node] + 1);
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      s.erase(s.find(max_dist[next_node] + 1));

      int max_s = *s.rbegin() + 1;
      self(self, next_node, node, max_s);

      s.insert(max_dist[next_node] + 1);
    }

    ans[node] = max(from_parent, *s.rbegin());
  };

  dfs2(dfs2, 1, 1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
