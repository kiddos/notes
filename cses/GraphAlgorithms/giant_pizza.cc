#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  // 2 sat
  vector<pair<int,int>> vars;
  for (int i = 0; i < n; ++i) {
    string c1, c2;
    int u = 0, v = 0;
    cin >> c1 >> u >> c2 >> v;
    u--;
    v--;

    int a = 0, b = 0;
    if (c1 == "+") {
      a = u * 2 + 1;
    } else {
      a = u * 2;
    }
    if (c2 == "+") {
      b = v * 2 + 1;
    } else {
      b = v * 2;
    }

    vars.emplace_back(a, b);
  }

  vector<pair<int,int>> edges;
  for (auto [v1, v2] : vars) {
    int not_v1 = v1 ^ 1;
    int not_v2 = v2 ^ 1;
    // cout << "v1=" << v1 << ",not_v1=" << not_v1 << ",v2=" << v2 << ",not_v2=" << not_v2 << endl;
    edges.emplace_back(v1, not_v2);
    edges.emplace_back(v2, not_v1);
  }

  vector<vector<int>> adj1(m * 2);
  vector<vector<int>> adj2(m * 2);
  for (auto [a, b] : edges) {
    adj1[a].push_back(b);
    adj2[b].push_back(a);
  }

  // kosaraju strongly connected component
  vector<bool> visited(m * 2);
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

  for (int i = 0; i < m * 2; ++i) {
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

  vector<int> cids(m * 2);
  int cid = 1;
  vector<vector<int>> components;
  while (!ordering.empty()) {
    int starting_node = ordering.back();
    ordering.pop_back();

    vector<int> component;
    dfs2(dfs2, starting_node, component);
    if (component.size()) {
      for (int node : component) {
        cids[node] = cid;
      }
      cid++;
      components.push_back(component);
    }
  }

  for (int i = 0; i < 2 * m; i += 2) {
    if (cids[i] == cids[i+1]) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  vector<bool> values(m * 2);
  for (vector<int>& c : components) {
    bool found_not = false;
    for (int var : c) {
      int not_var = var ^ 1;
      if (values[not_var]) {
        found_not = true;
        break;
      }
    }

    for (int var : c) {
      values[var] = !found_not;
    }
  }

  // for (int i = 0; i < m * 2; ++i) {
  //   cout << values[i] << " ";
  // }
  // cout << endl;

  vector<char> ans(m, ' ');
  for (int i = 0; i < m; ++i) {
    if (values[i*2]) {
      ans[i] = '-';
    } else {
      ans[i] = '+';
    }
  }

  for (char ch : ans) {
    cout << ch << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
