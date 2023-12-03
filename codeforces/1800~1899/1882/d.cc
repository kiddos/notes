#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> nodes(n+1);
  function<void(int,int)> count_nodes = [&](int node, int parent) {
    nodes[node] += 1;
    for (int child : adj[node]) if (child != parent) {
      count_nodes(child, node);
      nodes[node] += nodes[child];
    }
  };

  count_nodes(1, -1);

  function<i64(int,int,int,bool)> init_dfs = [&](int node, int parent, int bit, bool on) -> i64 {
    i64 ans = 0;
    bool x = false;
    if ((on && (!(a[node] & (1 << bit)))) || (!on && (a[node] & (1 << bit)))) {
      x = true;
    }

    for (int child : adj[node]) if (child != parent) {
      i64 result = init_dfs(child, node, bit, x ? !on : on);
      ans += result;
    }

    if (x) {
      ans += nodes[node] * (1LL << bit);
    }
    return ans;
  };

  constexpr int MAX_BIT = 20;
  i64 current = 0;
  for (int i = 0; i < MAX_BIT; ++i) {
    i64 result = min(init_dfs(1, -1, i, false), init_dfs(1, -1, i, true));
    current += result;
  }

  vector<i64> ans(n+1);
  function<void(int,int,i64)> dfs = [&](int node, int parent, i64 val) {
    ans[node] = val;

    for (int child : adj[node]) if (child != parent) {
      int child_nodes = nodes[child];
      int other_nodes = n - child_nodes;
      i64 x = a[child] ^ a[node];
      i64 new_val = val - child_nodes * x + other_nodes * x;
      dfs(child, node, new_val);
    }
  };

  dfs(1, -1, current);

  for (int node = 1; node <= n; ++node) {
    cout << ans[node] << " ";
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
