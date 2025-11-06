#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> parent(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> parent[i];
  }
  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  vector<int> children(n+1);
  auto dfs = [&](const auto& self, int node) -> void {
    for (int next_node : adj[node]) {
      self(self, next_node);
      children[node] += children[next_node] + 1;
    }
  };

  dfs(dfs, 1);

  for (int i = 1; i <= n; ++i) {
    cout << children[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
