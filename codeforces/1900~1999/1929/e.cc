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

  int k = 0;
  cin >> k;
  vector<pair<int,int>> pairs;
  for (int i = 0; i < k; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    pairs.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < (int) edges.size(); ++i) {
    auto e = edges[i];
    int u = e.first, v = e.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> flag(n+1);
  for (int i = 0; i < (int)pairs.size(); ++i) {
    auto p = pairs[i];
    int a = p.first, b = p.second;
    flag[a] |= (1<<i);
    flag[b] |= (1<<i);
  }

  vector<vector<int>> sets(k);
  function<void(int,int)> dfs = [&](int node, int p) {
    for (int next_node : adj[node]) if (next_node != p) {
      dfs(next_node, node);
      flag[node] ^= flag[next_node];
    }

    for (int next_node : adj[node]) if (next_node != p) {
      for (int i = 0; i < k; ++i) {
        if (~flag[node] & flag[next_node] & (1<<i)) {
          sets[i].push_back(flag[next_node]);
        }
      }
    }
  };

  dfs(1, -1);

  constexpr int INF = 100000000;
  int m = 1<<k;
  vector<int> dp(m, INF);
  dp[0] = 0;
  for (int mask = 0; mask < m; ++mask) {
    if (dp[mask] >= INF) continue;

    for (int b = 0; b < k; ++b) {
      for (int mask2 : sets[b]) {
        int new_mask = mask | mask2;
        dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
      }
    }
  }

  int ans = dp[(1<<k)-1];
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}