#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Result {
  bool require;
  bool found_y;
};

void solve() {
  string s;
  getline(cin, s);

  int n = 0, k = 0;
  cin >> n >> k;
  int x = 0, y = 0;
  cin >> x >> y;

  vector<int> a(k);
  for (int i = 0; i < k; ++ i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_set<int> indices(a.begin(), a.end());

  vector<int> dist(n+1);
  function<void(int,int)> compute_dist = [&](int node, int p) {
    for (int next_node : adj[node]) if (next_node != p) {
      dist[next_node] = dist[node]+1;
      compute_dist(next_node, node);
    }
  };

  compute_dist(x, -1);

  int ans = 0;
  function<Result(int,int)> dfs = [&](int node, int p) -> Result {
    bool require = indices.count(node);
    bool found_y = node == y;
    for (int next_node : adj[node]) if (next_node != p) {
      auto result = dfs(next_node, node);
      require = require || result.require;
      found_y = found_y || result.found_y;
    }

    if (node != x) {
      if (require && found_y) {
        // cout << "found y and require: " << node << endl;
        ans++;
      } else if (require) {
        // cout << "need to go back: " << node << endl;
        ans += 2;
      } else if (found_y) {
        // cout << "y path: " << node << endl;
        ans++;
      }
    }
    return Result{require, found_y};
  };

  dfs(x, -1);
  
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
