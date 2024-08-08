#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  i64 max_child = 0;
  for (int i = 2; i <= n; ++i) {
    max_child = max(max_child, a[i]);
  }

  function<bool(int,i64)> dfs = [&](int node, i64 ops) -> bool {
    if (ops > max_child) {
      return false;
    }

    if (adj[node].size() == 0) {
      return a[node] >= ops;
    }
    i64 more_ops = max(ops - a[node], 0LL);
    for (int next_node : adj[node]) {
      if (!dfs(next_node, ops + more_ops)) {
        return false;
      }
    }
    return true;
  };

  auto possible = [&](i64 value) -> bool {
    if (a[1] >= value) {
      return true;
    }
    for (int next_node : adj[1]) {
      if (!dfs(next_node, value - a[1])) {
        return false;
      }
    }
    return true;
  };

  i64 l = a[1], r = accumulate(a.begin(), a.end(), 0LL);
  i64 ans = l;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid-1;
    }
  }

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
