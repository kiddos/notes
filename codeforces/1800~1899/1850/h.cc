#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<pair<int,ll>>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, d = 0;
    cin >> a >> b >> d;
    adj[a].emplace_back(b, d);
    adj[b].emplace_back(a, -d);
  }

  vector<bool> visited(n+1);
  vector<ll> dist(n+1);
  
  function<bool(int,ll)> dfs = [&](int soldier, ll d) -> bool {
    if (visited[soldier]) {
      return dist[soldier] == d;
    }
    visited[soldier] = true;
    dist[soldier] = d;

    for (auto& [next_soldier, displace] : adj[soldier]) {
      bool result = dfs(next_soldier, d + displace);
      if (!result) {
        return false;
      }
    }
    return true;
  };

  for (int soldier = 1; soldier <= n; ++soldier) {
    if (!visited[soldier]) {
      if (!dfs(soldier, 0LL)) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout <<  "YES" << endl;
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
