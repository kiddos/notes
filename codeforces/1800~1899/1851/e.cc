#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<i64> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  vector<bool> has(n+1);
  for (int i = 0; i < k; ++i) {
    int p = 0;
    cin >> p;
    has[p] = true;
  }

  vector<vector<int>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    int m = 0;
    cin >> m;

    for (int j = 0; j < m; ++j) {
      int e = 0;
      cin >> e;
      adj[i].push_back(e);
    }
  }

  vector<i64> memo(n+1, -1);
  function<i64(int)> dfs = [&](int potion) -> i64 {
    if (has[potion]) {
      return 0;
    }
    if (adj[potion].empty()) {
      return c[potion];
    }
    if (memo[potion] >= 0) {
      return memo[potion];
    }

    i64 total = 0;
    for (int p2 : adj[potion]) {
      total += dfs(p2);
    }
    return memo[potion] = min(total, c[potion]);
  };

  for (int p = 1; p <= n; ++p) {
    cout << dfs(p) << " ";
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
