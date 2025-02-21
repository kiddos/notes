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
  for (int node = 2; node <= n; ++node) {
    adj[p[node]].push_back(node);
  }

  int ans = 1;
  function<pair<int,int>(int)> dfs = [&](int node) -> pair<int,int> {
    int max_d = 1;
    int total = 0;
    for (int child : adj[node]) {
      auto [child_max_inc, child_max_depth] = dfs(child);
      total += child_max_inc;
      max_d = max(max_d, child_max_depth + 1);
    }
    int max_inc = max({max_d, total});
    ans = max(ans, max_inc);
    return {max_inc, max_d};
  };

  dfs(1);

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
