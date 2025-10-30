#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> k(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
  }

  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  // kosaraju strongly connected component
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

  int cid = 0;
  vector<int> cids(n+1);
  vector<i64> cvalues;
  while (!ordering.empty()) {
    int starting_node = ordering.back();
    ordering.pop_back();

    vector<int> component;
    dfs2(dfs2, starting_node, component);
    if (component.size()) {
      i64 sum = 0;
      for (int node : component) {
        cids[node] = cid;
        sum += k[node];
      }
      cvalues.push_back(sum);
      cid++;
    }
  }

  // compress the graph
  vector<vector<int>> adj3(cid);
  for (auto [a, b] : edges) {
    int cid1 = cids[a];
    int cid2 = cids[b];
    if (cid1 != cid2) {
      adj3[cid1].push_back(cid2);
    }
  }
  for (vector<int>& a : adj3) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
  }

  vector<i64> memo(cid, -1);
  auto dfs3 = [&](const auto& self, int c) -> i64 {
    if (memo[c] >= 0) {
      return memo[c];
    }

    i64 ans = cvalues[c];
    for (int next_c : adj3[c]) {
      ans = max(ans, self(self, next_c) + cvalues[c]);
    }
    return memo[c] = ans;
  };

  i64 ans = 0;
  for (int c = 0; c < cid; ++c) {
    ans = max(ans, dfs3(dfs3, c));
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
