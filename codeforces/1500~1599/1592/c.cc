#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int x = 0;
  for (int i = 1; i <= n; ++i) {
    x ^= a[i];
  }

  bool ans = false;
  function<int(int,int)> dfs1 = [&](int node, int p) -> int {
    int sub = a[node];
    for (int next_node : adj[node]) if (next_node != p) {
      sub ^= dfs1(next_node, node);
    }
    if (p != -1 && (sub ^ x) == sub) {
      ans = true;
    }
    return sub;
  };

  dfs1(1, -1);

  int x_count = 0;
  function<int(int,int)> dfs2 = [&](int node, int p) -> int {
    int sub = a[node];
    for (int next_node : adj[node]) if (next_node != p) {
      sub ^= dfs2(next_node, node);
    }
    if (sub == x) {
      x_count++;
      return 0;
    }
    return sub;
  };

  if (k > 2) {
    dfs2(1, -1);
  }

  if (ans || (x_count >= 2)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
