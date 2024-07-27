#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> adj(n+1);
  vector<int> degree(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  vector<bool> is_bud(n+1);
  function<bool(int,int)> dfs = [&](int node, int p) -> bool {
    for (int next_node : adj[node]) {
      if (next_node != p) {
        if (dfs(next_node, node)) {
          degree[node]--;
        }
      }
    }

    bool all_leaf = true;
    for (int next_node : adj[node]) {
      if (next_node != p) {
        if (degree[next_node] != 1 && !is_bud[next_node]) {
          all_leaf = false;
        }
      }
    }

    if (node != 1 && degree[node] > 1 && all_leaf) {
      // cout << "node=" << node << " is bud" << endl;
      return is_bud[node] = true;
    }
    return false;
  };

  dfs(1, -1);

  int bud_count = 0;
  for (int node = 1; node <= n; ++node) {
    if (is_bud[node]) {
      bud_count++;
    }
  }
  // cout << "k=" << bud_count << endl;

  int ans = n - bud_count * 2;
  bool root_has_children = false;
  for (int next_node : adj[1]) {
    if (degree[next_node] == 1) {
      root_has_children = true;
    }
  }

  if (root_has_children) {
    ans--;
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
