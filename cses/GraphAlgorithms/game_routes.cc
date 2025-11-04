#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[b].push_back(a);
  }

  constexpr int MOD = 1e9 + 7;
  vector<i64> memo(n+1, -1);
  auto dfs = [&](const auto& self, int node) -> i64 {
    if (node == 1) {
      return 1;
    }
    if (memo[node] >= 0) {
      return memo[node];
    }
    i64 ans = 0;
    for (int prev_node : adj[node]) {
      ans += self(self, prev_node);
      ans %= MOD;
    }
    return memo[node] = ans;
  };

  i64 ans = dfs(dfs, n);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
