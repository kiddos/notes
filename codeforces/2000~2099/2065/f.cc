#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_major(vector<int>& path, int x) {
  if (path.size() <= 1) {
    return false;
  }
  int count = 0;
  for (int y : path) {
    count += y == x;
  }
  return count > (int)path.size() / 2;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> ans(n+1);

  function<void(int,int)> dfs = [&](int node, int p) {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dfs(next_node, node);
    }

    vector<int>& others = adj[node];
    map<int,int> count;
    count[a[node]] = 1;
    for (int other : others) {
      count[a[other]]++;
    }
    for (auto [x, c] : count) {
      if (c >= 2) {
        ans[x] = true;
      }
    }
  };

  dfs(1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << ans[i];
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
