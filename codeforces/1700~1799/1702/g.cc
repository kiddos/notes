#include <bits/stdc++.h>

using namespace std;

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

  int L = log2(n)+1;
  vector<vector<int>> parents(n+1, vector<int>(L));
  vector<int> depth(n+1);
  function<void(int,int,int)> dfs = [&](int x, int p, int d) {
    depth[x] = d;
    for (int y : adj[x]) if (y != p) {
      parents[y][0] = x;
      dfs(y, x, d+1);
    }
  };
  dfs(1, -1, 0);

  for (int l = 1; l < L; ++l) {
    for (int node = 1; node <= n; ++node) {
        parents[node][l] = parents[parents[node][l-1]][l-1];
    }
  }

  function<int(int,int)> find_lca = [&](int a, int b) -> int {
    if (depth[a] > depth[b]) {
      swap(a, b);
    }

    int depth_diff = depth[b] - depth[a];
    for (int l = 0; l < L; ++l) if (depth_diff & (1<<l)) {
      b = parents[b][l];
    }

    if (a == b) {
      return a;
    }

    for (int l = L-1; l >= 0; --l) {
      if (parents[a][l] != parents[b][l]) {
        a = parents[a][l];
        b = parents[b][l];
      }
    }
    return parents[a][0];
  };

  auto dist = [&](int a, int b) {
    int lca = find_lca(a, b);
    return depth[a] + depth[b] - 2 * depth[lca];
  };

  auto process_query = [&](vector<int>& nodes) -> bool {
    // find the 2 ends of the simple path
    sort(nodes.begin(), nodes.end(), [&](int a, int b) {
      return depth[a] > depth[b];
    });

    int u = nodes[0];
    int longest = 0;
    int v = u;
    for (int node : nodes) {
      int d = dist(node, u);
      if (d > longest) {
        v = node;
        longest = dist(node, u);
      }
    }

    // cout << "lca=" << find_lca(u, v) << endl;
    // cout << "u=" << u << ", v=" << v << endl;
    // cout << "longest=" << longest << endl;

    for (int node : nodes) {
      if (dist(node, u) + dist(node, v) != longest) {
        return false;
      }
    }
    return true;
  };

  int q = 0;
  cin >> q;
  while (q-- > 0) {
    int k = 0;
    cin >> k;
    vector<int> nodes(k);
    for (int i = 0; i < k; ++i) cin >> nodes[i];

    bool ans = process_query(nodes);
    if (ans) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
