#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
  int u, v;
  ll w;
};

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;

  vector<vector<pair<int,ll>>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    ll w = 0;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  set<int> valid_x;
  function<void(int,int,ll)> dfs1 = [&](int node, int parent, ll x) {
    for (auto& [next_node, w] : adj[node]) if (next_node != parent) {
      ll x2 = x ^ w;
      dfs1(next_node, node, x2);
      valid_x.insert(x2);
    }
  };

  dfs1(b, -1, 0);

  // cout << "x:" << endl;
  // for (int x : valid_x) cout << x << " ";
  // cout << endl;

  bool ans = false;
  function<void(int,int,ll)> dfs2 = [&](int node, int parent, ll x) {
    if (valid_x.count(x)) {
      ans = true;
    }

    for (auto& [next_node, w] : adj[node]) if (next_node != parent) {
      ll x2 = x ^ w;
      if (next_node == b && x2 == 0) {
        ans = true;
      }
      if (next_node != b) {
        dfs2(next_node, node, x2);
      }
    }
  };

  dfs2(a, -1, 0);

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
