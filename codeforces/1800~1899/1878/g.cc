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

  // precompute for LCA
  int log_n = ceil(log2(n))+1;
  vector<int> depths(n+1);
  vector<vector<int>> parents(n+1, vector<int>(log_n));
  parents[1] = vector<int>(log_n, 1);
  function<void(int,int)> dfs1 = [&](int node, int p) {
    for (int next_node : adj[node]) if (p != next_node) {
      parents[next_node][0] = node;
      depths[next_node] = depths[node]+1;
      dfs1(next_node, node);
    }
  };

  dfs1(1, 0);

  for (int l = 1; l < log_n; ++l) {
    for (int node = 1; node <= n; ++node) {
      int p = parents[node][l-1];
      parents[node][l] = parents[p][l-1];
    }
  }

  auto lca = [&](int x, int y) -> int {
    if (depths[x] < depths[y]) {
      swap(x, y);
    }
    int d = depths[x] - depths[y];
    for (int l = 0; l < log_n; ++l) if (d & (1<<l)) {
      x = parents[x][l];
    }

    if (y == x) {
      return x;
    }

    for (int l = log_n-1; l >= 0; --l) {
      if (parents[x][l] != parents[y][l]) {
        x = parents[x][l];
        y = parents[y][l];
      }
    }
    return parents[x][0];
  };

  auto is_ancestor = [&](int x, int y) -> bool {
    int ancestor = lca(x, y);
    return ancestor == x;
  };

  // compute bit counts
  constexpr int BIT_COUNT = 30;
  vector<array<int,BIT_COUNT>> bit_counts(n+1);
  function<void(int,int)> dfs2 = [&](int node, int p) {
    for (int b = 0; b < BIT_COUNT; ++b) {
      if (a[node] & (1<<b)) {
        bit_counts[node][b]++;
      }
      if (p > 0) {
        bit_counts[node][b] += bit_counts[p][b];
      }
    }

    for (int next_node : adj[node]) if (p != next_node) {
      dfs2(next_node, node);
    }
  };

  dfs2(1, 0);

  auto g = [&](int x, int y) -> i64 {
    int ancestor = lca(x, y);
    vector<int> c(BIT_COUNT);
    for (int b = 0; b < BIT_COUNT; ++b) {
      c[b] += bit_counts[x][b];
      c[b] += bit_counts[y][b];
      c[b] -= 2 * bit_counts[ancestor][b];
      if (a[ancestor] & (1<<b)) {
        c[b]++;
      }
    }
    i64 ans = 0;
    for (int b = 0; b < BIT_COUNT; ++b) if (c[b] > 0) {
      ans++;
    }
    //cout << "g(" << x << "," << y << ")=" << ans << endl;
    return ans;
  };

  // find closest ancestor with bit b
  vector<vector<int>> found(BIT_COUNT);
  vector<vector<int>> closest(n+1, vector<int>(BIT_COUNT, -1));
  function<void(int,int)> dfs3 = [&](int node, int p) {
    for (int b = 0; b < BIT_COUNT; ++b) {
      if (!found[b].empty()) {
        closest[node][b] = found[b].back();
      }
    }
    for (int b = 0; b < BIT_COUNT; ++b) {
      if (a[node] & (1<<b)) {
        found[b].push_back(node);
      }
    }

    for (int next_node : adj[node]) if (p != next_node) {
      dfs3(next_node, node);
    }

    for (int b = 0; b < BIT_COUNT; ++b) {
      if (a[node] & (1<<b)) {
        found[b].pop_back();
      }
    }
  };

  dfs3(1, 0);


  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;

    int ancestor = lca(x, y);
    //cout << "x=" << x << ",y=" << y << ", ancestor=" << ancestor << endl;
    vector<int> zs = {x, y};
    for (int b = 0; b < BIT_COUNT; ++b) {
      if (closest[x][b] > 0 && is_ancestor(ancestor, closest[x][b])) {
        zs.push_back(closest[x][b]);
      }
      if (closest[y][b] > 0 && is_ancestor(ancestor, closest[y][b])) {
        zs.push_back(closest[y][b]);
      }
    }
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());

    i64 ans = 0;
    for (int z : zs) {
      ans = max(ans, g(x, z) + g(y, z));
    }
    cout << ans << " ";
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
