#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  int m1 = 0;
  cin >> m1;
  vector<int> a(m1);
  vector<bool> a_should_visit(n+1);
  for (int i = 0; i < m1; ++i) {
    cin >> a[i];
    a_should_visit[a[i]] = true;
  }
  int m2 = 0;
  cin >> m2;
  vector<int> b(m2);
  vector<bool> b_should_visit(n+1);
  for (int i = 0; i < m2; ++i) {
    cin >> b[i];
    b_should_visit[b[i]] = true;
  }

  vector<vector<int>> adj = vector<vector<int>>(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> p0(n+1);
  function<void(int,int)> dfs1 = [&](int node, int p) {
    p0[node] = p;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dfs1(next_node, node);
    }
  };
  dfs1(1, 1);

  int L = ceil(log2(n));
  vector<vector<int>> parents(L + 1, vector<int>(n+1));
  parents[0] = p0;
  for (int l = 1; l <= L; ++l) {
    for (int node = 1; node <= n; ++node) {
      parents[l][node] = parents[l-1][parents[l-1][node]];
    }
  }

  auto dth_ancestor = [&](int node) -> int {
    for (int l = 0; l <= L; ++l) {
      if (d & (1<<l)) {
        node = parents[l][node];
      }
    }
    return node;
  };

  function<void(int,int,vector<bool>&,vector<bool>&)> dfs2 = [&](int node, int p, vector<bool>& s1, vector<bool>& s2) {
    if (s1[node]) {
      int ancestor = dth_ancestor(node);
      s2[ancestor] = true;
    }
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dfs2(next_node, node, s1, s2);
    }
  };

  dfs2(1, 1, a_should_visit, b_should_visit);
  dfs2(1, 1, b_should_visit, a_should_visit);

  i64 ans = 0;
  function<int(int,int,vector<bool>&)> dfs3 = [&](int node, int p, vector<bool>& s) -> int {
    bool should_visit = s[node];
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      bool result = dfs3(next_node, node, s);
      if (result) {
        ans += 2;
      }
      should_visit = should_visit || result;
    }
    return should_visit;
  };

  dfs3(1, 1, a_should_visit);
  dfs3(1, 1, b_should_visit);

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
