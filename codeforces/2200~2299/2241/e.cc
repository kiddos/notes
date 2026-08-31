#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// u w v
// p(u, v) = a[u] * a[w] * a[v]
// p(v, w) = a[v] * a[w]
// p(w, u) = a[w] * a[u]
// p(u, v) * p(v, w) * p(w, u) = a[u] ^ 2 * a[v] ^ 2 * a[w] ^ 3
// perfect square is determined by a[w] if a[w] is a perfect square itself
// u i w j v
// p(u, v) = a[u] * a[i] * a[w] * a[j] * a[v]
// p(v, w) = a[v] * a[j] * a[w]
// p(w, u) = a[w] * a[i] * a[u]
// p(u, v) * p(v, w) * p(w, u) = a[u] ^ 2 * a[v] ^ 2 * a[i] ^ 2 * a[j] ^ 2 * a[w] ^ 3
// still determined by a[w]
// w = v
// u v
// p(u, v) = a[u] * a[v]
// p(v, w) = a[v]
// p(w, u) = a[v] * a[u]
// p(u, v) * p(v, w) * p(w, u) = a[u] ^ 2 * a[v] ^ 3
// still determined by a[w]

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<bool> is_perfect_square(n+1);
  for (int i = 1; i <= n; ++i) {
    int sq = sqrt(a[i]);
    is_perfect_square[i] = sq * sq == a[i];
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> size(n+1, 1);
  auto dfs1 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      size[node] += size[next_node];
    }
  };

  dfs1(dfs1, 1, 1);

  i64 ans = 0;
  auto dfs2 = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }

    vector<int> components;
    if (is_perfect_square[node]) {
      for (int next_node : adj[node]) {
        if (next_node == p) {
          continue;
        }
        components.push_back(size[next_node]);
      }
      if (n - size[node] > 0) {
        components.push_back(n - size[node]);
      }

      i64 triples = 0, pairs = 0, single = 0;
      for (int s : components) {
        triples += s * pairs;
        pairs += s * single;
        single += s;
      }
      ans += triples + pairs;
    }
  };

  dfs2(dfs2, 1, 1);

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
