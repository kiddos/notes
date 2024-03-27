#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int max_a = max_element(a.begin(), a.end()) - a.begin();
  int max_b = max_element(b.begin(), b.end()) - b.begin();

  vector<vector<int>> adj(n);
  vector<array<int,3>> players;
  for (int i = 0; i < n; ++i) {
    players.push_back({a[i], b[i], i});
  }
  sort(players.begin(), players.end());
  for (int i = 1; i < n; ++i) {
    int u = players[i][2], v = players[i-1][2];
    adj[v].push_back(u);
  }
  sort(players.begin(), players.end(), [&](auto& p1, auto& p2) {
    return p1[1] < p2[1];
  });
  for (int i = 1; i < n; ++i) {
    int u = players[i][2], v = players[i-1][2];
    adj[v].push_back(u);
  }

  vector<int> ans(n);
  function<void(int)> dfs = [&](int p) {
    if (ans[p]) {
      return;
    }
    ans[p] = true;
    for (int p2 : adj[p]) {
      dfs(p2);
    }
  };

  dfs(max_a);
  dfs(max_b);

  for (int i = 0; i < n; ++i) cout << ans[i];
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
