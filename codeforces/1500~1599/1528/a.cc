#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> l(n+1), r(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
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

  function<array<i64,2>(int,int)> dfs = [&](int node, int p) -> array<i64,2> {
    i64 left = 0, right = 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      auto [choose_left, choose_right] = dfs(next_node, node);
      left += max(
        abs(l[node] - l[next_node]) + choose_left,
        abs(l[node] - r[next_node]) + choose_right
      );
      right += max(
        abs(r[node] - l[next_node]) + choose_left,
        abs(r[node] - r[next_node]) + choose_right
      );
    }
    return {left, right};
  };

  auto [left, right] = dfs(1, 0);
  i64 ans = max(left, right);
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
