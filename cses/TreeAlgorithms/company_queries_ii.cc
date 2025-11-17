#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> parent(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    cin >> parent[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  vector<int> depth(n+1);
  auto dfs = [&](const auto& self, int node) -> void {
    for (int next_node : adj[node]) {
      depth[next_node] = depth[node] + 1;
      self(self, next_node);
    }
  };

  dfs(dfs, 1);

  int L = ceil(log2(n)) + 1;
  vector<vector<int>> binary_lift(L, vector<int>(n+1));
  binary_lift[0] = parent;
  for (int l = 1; l < L; ++l) {
    for (int i = 1; i <= n; ++i) {
      binary_lift[l][i] = binary_lift[l-1][binary_lift[l-1][i]];
    }
  }

  auto lca = [&](int a, int b) -> int {
    if (depth[a] < depth[b]) {
      swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int l = L-1; l >= 0; --l) {
      if (diff & (1<<l)) {
        a = binary_lift[l][a];
      }
    }
    if (a == b) {
      return a;
    }

    for (int l = L-1; l >= 0; --l) {
      if (binary_lift[l][a] != binary_lift[l][b]) {
        a = binary_lift[l][a];
        b = binary_lift[l][b];
      }
    }
    return binary_lift[0][a];
  };

  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    ans[i] = lca(a, b);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
