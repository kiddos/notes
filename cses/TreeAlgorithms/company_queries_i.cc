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

  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int x = 0, k = 0;
    cin >> x >> k;
    if (depth[x] < k) {
      ans[i] = -1;
    } else {
      for (int l = L-1; l >= 0; --l) {
        if (k & (1<<l)) {
          x = binary_lift[l][x];
        }
      }
      ans[i] = x;
    }
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
