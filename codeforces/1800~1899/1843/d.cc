#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  vector<int> children_count(n+1);
  function<void(int,int)> dfs = [&](int node, int parent) {
    int num_children = 0;
    for (int next_node : adj[node]) if (next_node != parent) {
      dfs(next_node, node);
      num_children += children_count[next_node];
    }
    if (num_children == 0) {
      children_count[node] = 1;
    } else {
      children_count[node] = num_children;
    }
  };

  dfs(1, -1);

  int q = 0;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;

    ll c1 = children_count[x], c2 = children_count[y];
    cout << c1 * c2 << endl;
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
