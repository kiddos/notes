#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> parent(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> parent[i];
  }
  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  vector<int> d(n+1);
  function<void(int)> compute_depth = [&](int node) {
    for (int next_node : adj[node]) {
      d[next_node] = d[node] + 1;
      compute_depth(next_node);
    }
  };
  compute_depth(1);

  int max_depth = *max_element(d.begin()+1, d.end());
  vector<vector<int>> nodes_by_depth(max_depth+2);
  for (int node = 1; node <= n; ++node) {
    nodes_by_depth[d[node]].push_back(node);
  }

  constexpr int MOD = 998244353;
  vector<i64> dp(n+1);
  dp[1] = 1;
  for (int d = 0; d <= max_depth; ++d) {
    i64 total = 0;
    for (int node : nodes_by_depth[d]) {
      total += dp[node];
      total %= MOD;
      if (node > 1) {
        for (int next_node : adj[node]) {
          dp[next_node] -= dp[node];
          dp[next_node] %= MOD;
          dp[next_node] += MOD;
          dp[next_node] %= MOD;
        }
      }
    }
    for (int next_node : nodes_by_depth[d+1]) {
      dp[next_node] += total;
      dp[next_node] %= MOD;
    }
  }

  i64 ans = 0;
  for (int node = 1; node <= n; ++node) {
    ans += dp[node];
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
