#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  i64 t0 = 0, t1 = 0, t2 = 0;
  cin >> t0 >> t1 >> t2;
  vector<vector<array<i64,3>>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    i64 u = 0, v = 0, l1 = 0, l2 = 0;
    cin >> u >> v >> l1 >> l2;
    adj[u].push_back({v, l1, l2});
    adj[v].push_back({u, l1, l2});
  }

  constexpr i64 INF = 100000000000000000LL;
  vector<i64> dist(n+1, -INF);
  dist[n] = t0;
  set<pair<i64, int>> s;
  s.insert({t0, n});
  while (!s.empty()) {
    auto [d, node] = *s.rbegin();
    s.erase(prev(s.end()));
    for (auto& [prev_node, l1, l2] : adj[node]) {
      i64 start = d - l1, end = d;
      i64 d2 = d - l1;
      if (!(start >= t2 || end <= t1)) {
        d2 = max(d - l2, t1 - l1);
      }
      if (d2 > dist[prev_node]) {
        s.erase({dist[prev_node], prev_node});
        dist[prev_node] = d2;
        s.insert({dist[prev_node], prev_node});
      }
    }
  }

  // for (int node = 1; node <= n; ++node) {
  //   cout << dp1[node] << " ";
  // }
  // cout << endl;
  // for (int node = 1; node <= n; ++node) {
  //   cout << dp2[node] << " ";
  // }
  // cout << endl;

  i64 ans = dist[1];
  if (ans < 0) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
