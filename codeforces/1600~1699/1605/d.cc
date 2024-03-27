#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> colors(n+1);
  function<void(int,int,int)> dfs = [&](int node, int p, int color) {
    colors[node] = color;
    for (int next_node : adj[node]) if (next_node != p) {
      dfs(next_node, node, 1-color);
    }
  };

  dfs(1, -1, 1);

  auto msb = [&](int x) -> int {
    for (int i = 30; i >= 0; --i) {
      if (x & (1<<i)) {
        return i;
      }
    }
    return -1;
  };

  vector<int> group1, group2;
  vector<vector<int>> msb_nodes(msb(n)+1);
  for (int i = 1; i <= n; ++i) {
    if (colors[i]) {
      group1.push_back(i);
    } else {
      group2.push_back(i);
    }

    msb_nodes[msb(i)].push_back(i);
  }

  if (group1.size() > group2.size()) {
    swap(group1, group2);
  }


  vector<int> ans(n+1);
  int i = 0, j = 0;
  for (int b = 0; b <= msb(n); ++b) {
    if (group1.size() & (1<<b)) {
      for (int new_val : msb_nodes[b]) {
        ans[group1[i++]] = new_val;
      }
    } else {
      for (int new_val : msb_nodes[b]) {
        ans[group2[j++]] = new_val;
      }
    }
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
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
