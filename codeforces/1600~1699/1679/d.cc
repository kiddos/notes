#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  i64 k = 0;
  cin >> n >> m >> k;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<bool> visited(n+1);
  vector<int> nodes;
  function<void(int)> top_sort = [&](int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      top_sort(next_node);
    }
    nodes.push_back(node);
  };

  for (int node = 1; node <= n; ++node) {
    if (visited[node]) {
      continue;
    }
    top_sort(node);
  }

  reverse(nodes.begin(), nodes.end());

  vector<i64> memo(n+1, -1);
  function<i64(int,int)> dfs = [&](int node, int max_val) -> i64 {
    if (a[node] > max_val) {
      return 0;
    }
    if (memo[node] >= 0) {
      return memo[node];
    }
    if (visited[node]) {
      // cout << "found cycle at " << node << endl;
      // found a cycle
      return k;
    }
    visited[node] = true;
    i64 ans = 1;
    for (int next_node : adj[node]) {
      ans = max(ans, dfs(next_node, max_val) + 1);
    }
    visited[node] = false;
    return memo[node] = ans;
  };

  auto path_found = [&](int max_val) -> bool {
    fill(visited.begin(), visited.end(), false);
    fill(memo.begin(), memo.end(), -1);
    for (int node : nodes) {
      // if (visited[node]) {
      //   continue;
      // }

      i64 len = dfs(node, max_val);
      if (len >= k) {
        return true;
      }
    }
    return false;
  };

  int l = *min_element(a.begin(), a.end());
  int r = *max_element(a.begin(), a.end());
  int ans = -1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (path_found(mid)) {
      // cout << "path found for " << mid << endl;
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
