#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<ll> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  
  vector<set<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;

    adj[u].insert(v);
    adj[v].insert(u);
  }

  vector<ll> importance = a;
  vector<int> size(n+1, 1);
  vector<int> parents(n+1, -1);
  function<void(int,int)> dfs1 = [&](int node, int parent) {
    parents[node] = parent;
    for (int child : adj[node]) if (child != parent) {
      dfs1(child, node);
      importance[node] += importance[child];
      size[node] += size[child];
    }
  };

  dfs1(1, -1);

  vector<set<pair<ll,int>>> children(n+1);
  function<void(int,int)> dfs2 = [&](int node, int parent) {
    for (int child : adj[node]) if (child != parent) {
      children[node].insert({-size[child], child});
      dfs2(child, node);
    }
  };

  dfs2(1, -1);

  function<int(int)> find_heavy = [&](int node) -> int {
    if (children[node].empty()) {
      return -1;
    }
    return children[node].begin()->second;
  };

  for (int i = 0; i < m; ++i) {
    int t = 0, x = 0;
    cin >> t >> x;

    if (t == 1) {
      cout << importance[x] << endl;
    } else if (t == 2) {
      int heavy = find_heavy(x);
      if (heavy == -1) {
        continue;
      }

      int x_parent = parents[x];

      // update size and children
      children[x].erase({-size[heavy], heavy});
      children[x_parent].erase({-size[x], x});
      size[x] -= size[heavy];
      size[heavy] += size[x];
      children[heavy].insert({-size[x], x});
      children[x_parent].insert({-size[heavy], heavy});

      // update importance
      importance[x] -= importance[heavy];
      importance[heavy] += importance[x];

      // update parent
      parents[x] = heavy;
      parents[heavy] = x_parent;

    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
