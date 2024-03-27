#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto possible = [&](int size) -> bool {
    int total = 0;
    function<int(int,int)> dfs = [&](int node, int p) -> int {
      int s = 1;
      for (int next_node : adj[node]) if (next_node != p) {
        s += dfs(next_node, node);
      }
      if (s >= size) {
        total++;
        return 0;
      }
      return s;
    };

    dfs(1, -1);
    return total > k;
  };

  int l = 1, r = n;
  int ans = 1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

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