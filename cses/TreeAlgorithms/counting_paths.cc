#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<pair<int,int>> paths;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    paths.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> depths(n+1);
  vector<int> parents(n+1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void {
    parents[node] = p;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      depths[next_node] = depths[node]+1;
      self(self, next_node, node);
    }
  };

  dfs1(dfs1, 1, 1);

  int L = ceil(log2(n)) + 1;
  vector<vector<int>> p(L, vector<int>(n+1));
  p[0] = parents;
  for (int l = 1; l < L; ++l) {
    for (int i = 1; i <= n; ++i) {
      p[l][i] = p[l-1][p[l-1][i]];
    }
  }

  auto lca = [&](int a, int b) -> int {
    if (depths[a] < depths[b]) {
      swap(a, b);
    }
    int diff = depths[a] - depths[b];
    for (int l = 0; l < L; ++l) {
      if (diff & (1<<l)) {
        a = p[l][a];
      }
    }
    if (a == b) {
      return a;
    }
    for (int l = L -1; l >= 0; --l) {
      if (p[l][a] != p[l][b]) {
        a = p[l][a];
        b = p[l][b];
      }
    }
    return p[0][a];
  };

  vector<int> prefix(n+1);
  for (auto [a, b] : paths) {
    prefix[a]++;
    prefix[b]++;
    int l = lca(a, b);
    prefix[l]--;
    int pl = p[0][l];
    if (pl != l) {
      prefix[pl]--;
    }
  }

  vector<int> ans(n+1);
  auto dfs2 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      prefix[node] += prefix[next_node];
    }
    ans[node] = prefix[node];
  };

  dfs2(dfs2, 1, 1);

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
