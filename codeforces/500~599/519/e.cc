#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  int m = 0;
  cin >> m;
  vector<int> x(m), y(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int L = log2(n) + 2;
  vector<vector<int>> parents(L, vector<int>(n+1));
  vector<int> dists(n+1);
  vector<int> sizes(n+1, 1);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    parents[0][node] = p;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dists[next_node] = dists[node] + 1;
      self(self, next_node, node);
      sizes[node] += sizes[next_node];
    }
  };
  dfs(dfs, 1, 0);

  for (int l = 1; l < L; ++l) {
    for (int node = 1; node <= n; ++node) {
      parents[l][node] = parents[l-1][parents[l-1][node]];
    }
  }

  auto lca = [&](int a, int b) -> int {
    if (dists[b] > dists[a]) {
      swap(a, b);
    }
    int depth_diff = dists[a] - dists[b];
    for (int l = L-1; l >= 0; --l) {
      if (depth_diff & (1<<l)) {
        a = parents[l][a];
      }
    }
    if (a == b) {
      return a;
    }

    for (int l = L-1; l >= 0; --l) {
      if (parents[l][a] != parents[l][b]) {
        a = parents[l][a];
        b = parents[l][b];
      }
    }
    return parents[0][a];
  };

  auto compute_dist = [&](int a, int b) -> int {
    int d1 = dists[a];
    int d2 = dists[b];
    int l = lca(a, b);
    // cout << "l=" << l << endl;
    int d3 = dists[l];
    // cout << "d1=" << d1 << ", d2=" << d2 << ", d3=" << d3 << endl;
    return d1 + d2 - d3 * 2;
  };

  auto find_middle = [&](int a, int b, int dist) -> int {
    int half = dist / 2;
    if (dists[b] > dists[a]) {
      swap(a, b);
    }
    for (int l = L-1; l >= 0; --l) {
      if (half & (1<<l)) {
        a = parents[l][a];
      }
    }
    return a;
  };

  auto find_child = [&](int node, int child) -> int {
    int move = dists[child] - dists[node] - 1;
    // cout << "child=" << child << ", node=" << node << endl;
    // cout << "move=" << move << endl;
    for (int l = L-1; l >= 0; --l) {
      if (move & (1<<l)) {
        child = parents[l][child];
      }
    }
    return child;
  };

  auto find_connected = [&](int mid, int a, int b) -> int {
    if (dists[b] > dists[a]) {
      swap(a, b);
    }
    if (dists[a] == dists[b]) {
      if (a == b) {
        return n;
      } else {
        int pa = find_child(mid, a);
        int pb = find_child(mid, b);
        // cout << "pa=" << pa << ", pb=" << pb << endl;
        return n - sizes[pa] - sizes[pb];
      }
    }
    int pa = find_child(mid, a);
    // cout << "pa=" <<pa << endl;
    return sizes[mid] - sizes[pa];
  };

  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    int d = compute_dist(x[i], y[i]);
    // cout << "x=" << x[i]  << ",y=" << y[i] << endl;
    if (d % 2 == 1) {
      ans.push_back(0);
    } else {
      int middle = find_middle(x[i], y[i], d);
      // cout << "middle=" << middle << endl;
      int connected = find_connected(middle, x[i], y[i]);
      ans.push_back(connected);
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
