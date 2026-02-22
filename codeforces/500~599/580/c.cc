#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    edges.emplace_back(x, y);
  }
  vector<vector<int>> adj(n+1);
  for (auto [x, y] : edges) {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  auto dfs = [&](const auto& self, int node, int p, int cat) -> int {
    if (a[node]) {
      cat++;
    } else {
      cat = 0;
    }
    if (cat > m) {
      return 0;
    }

    int ans = 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      ans += self(self, next_node, node, cat);
    }
    if (adj[node].size() == 1 && node != 1) {
      ans++;
    }
    return ans;
  };

  int ans = dfs(dfs, 1, 0, 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
