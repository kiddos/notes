#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }

  vector<i64> l(n+1), r(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  vector<int> ops(n+1);
  vector<i64> a(n+1);
  function<void(int)> dfs = [&](int node) {
    if (adj[node].size() == 0) {
      ops[node] = 1;
      a[node] = r[node];
      return;
    }

    i64 child_sum = 0;
    for (int child : adj[node]) {
      dfs(child);

      ops[node] += ops[child];
      child_sum += a[child];
    }

    if (child_sum < l[node]) {
      ops[node]++;
      a[node] = r[node];
    } else {
      a[node] = min(r[node], child_sum);
    }
  };

  dfs(1);

  int ans = ops[1];
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
