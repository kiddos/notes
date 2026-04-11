#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    if (p[i] >= 1) {
      adj[p[i]].push_back(i);
    }
  }

  vector<int> heights(n+1);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    heights[node] = 1;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      heights[node] = max(heights[node], heights[next_node]+1);
    }
  };

  for (int i = 1; i <= n; ++i) {
    if (!heights[i]) {
      dfs(dfs, i, 0);
    }
  }

  int ans = *max_element(heights.begin(), heights.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
