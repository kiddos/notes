#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 c = 0;
  cin >> n >> c;
  vector<i64> a(n+1);
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
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  constexpr i64 NOT_FOUND = numeric_limits<i64>::min();
  vector<vector<i64>> memo(n+1, vector<i64>(2, NOT_FOUND));
  function<i64(int,int,int)> dfs = [&](int node, int p, int d) -> i64 {
    if (memo[node][d] > NOT_FOUND) {
      return memo[node][d];
    }

    i64 ans = d ? a[node] : 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      if (d == 0) {
        ans += max(dfs(next_node, node, 0),
                   dfs(next_node, node, 1));
      } else {
        ans += max(dfs(next_node, node, 0),
                   dfs(next_node, node, 1) - 2 * c);
      }
    }
    return memo[node][d] = ans;
  };

  i64 ans = max(dfs(1, 0, 0), dfs(1, 0, 1));
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
