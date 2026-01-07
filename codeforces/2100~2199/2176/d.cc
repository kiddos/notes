#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
  }
  constexpr int MOD = 998244353;

  map<pair<int,i64>, i64> memo;
  auto dfs = [&](const auto& self, int node, i64 last_sum) -> i64 {
    pair<int,i64> key = {node, last_sum};
    if (memo.count(key)) {
      return memo[key];
    }

    i64 next_sum = a[node] + last_sum;
    i64 ans = 0;
    for (int next_node : adj[node]) {
      if (a[next_node] == next_sum) {
        ans += self(self, next_node, a[node]) + 1;
        ans %= MOD;
      }
    }
    return memo[key] = ans;
  };

  i64 ans = 0;
  for (int node = 1; node <= n; ++node) {
    for (int next_node : adj[node]) {
      i64 result = dfs(dfs, next_node, a[node]);
      ans += result;
      ans %= MOD;
    }
  }
  for (int node = 1; node <= n; ++node) {
    int size = adj[node].size();
    ans += size;
    ans %= MOD;
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
