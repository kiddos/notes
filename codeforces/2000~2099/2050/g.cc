#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
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

  int ans = 1;
  function<int(int,int)> dfs1 = [&](int node, int p) {
    vector<int> deg_increase;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      int result = dfs1(next_node, node);
      deg_increase.push_back(result);
    }

    sort(deg_increase.rbegin(), deg_increase.rend());
    int children_count = deg_increase.size();
    int remove_single_child = max(children_count, 1);
    int parent_component = (p ? 1 : 0);
    int remove_current = children_count + parent_component;
    if (deg_increase.size() >= 2) {
      int inc = children_count + deg_increase[0] + deg_increase[1] - 2;
      remove_current = max(remove_current, inc + parent_component);
    }
    if (deg_increase.size() >= 1) {
      int inc = children_count + deg_increase[0] - 1;
      remove_single_child = max(remove_single_child, inc);
      remove_current = max(remove_current, inc + parent_component);
    }
    ans = max(ans, remove_current);
    // cout << "node=" << node << ", remove=" << remove_current << endl;
    return remove_single_child;
  };

  dfs1(1, 0);

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
