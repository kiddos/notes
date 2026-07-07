#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<set<int>> s(n+1);
  vector<int> ans(n+1);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    s[node].insert(c[node]);
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);

      if (s[node].size() < s[next_node].size()) {
        swap(s[node], s[next_node]);
      }
      
      for (int color : s[next_node]) {
        s[node].insert(color);
      }
    }
    ans[node] = s[node].size();
  };

  dfs(dfs, 1, 1);

  for (int node = 1; node <= n; ++node) {
    cout << ans[node] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
