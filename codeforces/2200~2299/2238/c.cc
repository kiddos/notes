#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  i64 ans = n;
  auto dfs = [&](const auto& self, int node) -> int {
    int depth = 1;
    vector<int> children_depths;
    for (int next_node : adj[node]) {
      int d = self(self, next_node);
      depth = max(depth, d + 1);
      children_depths.push_back(d);
    }
    int count = adj[node].size();
    if (count > 1) {
      sort(children_depths.rbegin(), children_depths.rend());
      ans += children_depths[1];
    }
    return depth;
  };

  dfs(dfs, 1);
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
