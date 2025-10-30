#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj1(n+1);
  vector<vector<int>> adj2(n+1);
  for (auto [a, b] : edges) {
    adj1[a].push_back(b);
    adj2[b].push_back(a);
  }

  vector<bool> visited(n+1);
  vector<int> ordering;
  auto dfs1 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj1[node]) {
      self(self, next_node);
    }
    ordering.push_back(node);
  };

  for (int i = 1; i <= n; ++i) {
    dfs1(dfs1, i);
  }

  auto dfs2 = [&](const auto& self, int node, vector<int>& component) -> void {
    if (visited[node]) {
      visited[node] = false;
      component.push_back(node);
      for (int next_node : adj2[node]) {
        self(self, next_node, component);
      }
    }
  };

  int cid = 1;
  vector<int> ans(n+1);
  while (!ordering.empty()) {
    int starting_node = ordering.back();
    ordering.pop_back();
    vector<int> component;
    dfs2(dfs2, starting_node, component);
    if (component.size()) {
      for (int node : component) {
        ans[node] = cid;
      }
      cid++;
    }
  }

  cout << cid-1 << endl;
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
