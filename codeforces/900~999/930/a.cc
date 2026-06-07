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
  vector<int> dists(n+1);
  auto dfs = [&](const auto& self, int node) -> void {
    for (int next_node : adj[node]) {
      dists[next_node] = dists[node] + 1;
      self(self, next_node);
    }
  };

  dfs(dfs, 1);
  vector<int> count(n+1);
  for (int i = 1; i <= n; ++i) {
    count[dists[i]]++;
  }
  int ans = 0;
  for (int d = 0; d <= n; ++d) {
    ans += count[d] % 2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
