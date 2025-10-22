#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> depths(n);
  vector<int> parent(n);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      parent[next_node] = node;
      depths[next_node] = depths[node] + 1;
      self(self, next_node, node);
    }
  };

  dfs(dfs, 0, 0);

  int L = ceil(log2(n))+1;
  vector<vector<int>> binary_lift(L, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    binary_lift[0][i] = parent[i];
  }

  for (int l = 1; l < L; ++l) {
    for (int i = 0; i < n; ++i) {
      binary_lift[l][i] = binary_lift[l-1][binary_lift[l-1][i]];
    }
  }

  auto query = [&](int a, int b) -> int {
    if (depths[b] > depths[a]) {
      swap(a, b);
    }
    int diff = depths[a] - depths[b];
    for (int l = 0; l < L; ++l) {
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

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    int lca = query(a, b);
    // cout << "a=" << a <<",b=" << b << ",lca=" << lca << endl;
    int dist = depths[a] + depths[b] - depths[lca] * 2;
    ans.push_back(dist);
  }
  for (int d : ans) {
    cout << d << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
