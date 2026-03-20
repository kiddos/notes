#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> l(n+1), r(n+1);
  l[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    if (l[i]) {
      adj[i].push_back(l[i]);
    }
    if (r[i]) {
      adj[i].push_back(r[i]);
    }
  }

  vector<i64> t(n+1);
  auto dfs1 = [&](const auto& self, int node) -> void {
    for (int child : adj[node]) {
      self(self, child);
      t[node] += t[child] + 2;
    }
  };

  constexpr int MOD = 1e9+7;
  dfs1(dfs1, 1);
  vector<i64> ans(n+1);
  ans[1] = t[1] % MOD;

  auto dfs2 = [&](const auto& self, int node, i64 additional) -> void {
    if (node > 1) {
      ans[node] = (t[1] + additional) % MOD;
    }
    for (int child : adj[node]) {
      self(self, child, (additional + t[child] + 1) % MOD);
    }
  };

  dfs2(dfs2, 1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << (ans[i]+1) % MOD << " ";
  }
  cout << endl;
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
