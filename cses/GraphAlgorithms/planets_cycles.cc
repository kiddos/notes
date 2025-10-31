#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> t(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  vector<vector<int>> adj1(n+1);
  vector<vector<int>> adj2(n+1);
  for (int i = 1; i <= n; ++i) {
    adj1[i].push_back(t[i]);
    adj2[t[i]].push_back(i);
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

  vector<vector<int>> components;
  while (!ordering.empty()) {
    int node0 = ordering.back();
    ordering.pop_back();
    vector<int> component;
    dfs2(dfs2, node0, component);
    if (component.size()) {
      components.push_back(component);
    }
  }

  int size = components.size();
  vector<int> component_size(size);
  vector<int> cids(n+1);
  for (int i = 0; i < size; ++i) {
    component_size[i] = components[i].size();
    for (int node : components[i]) {
      cids[node] = i;
    }
  }

  vector<vector<int>> adj3(size);
  for (int i = 1; i <= n; ++i) {
    int cid1 = cids[i];
    int cid2 = cids[t[i]];
    adj3[cid1].push_back(cid2);
  }

  for (int c = 0; c < size; ++c) {
    vector<int>& a = adj3[c];
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
  }

  vector<bool> cvisited(size);
  vector<int> component_sizes(size);
  auto dfs3 = [&](const auto& self, int c) -> int {
    if (components[c].size() > 1) {
      return component_sizes[c] = components[c].size();
    }
    if (component_sizes[c]) {
      return component_sizes[c];
    }
    if (cvisited[c]) {
      return 0;
    }
    cvisited[c] = true;

    int ans = 0;
    for (int prev_c : adj3[c]) {
      ans += self(self, prev_c) + 1;
    }
    return component_sizes[c] = ans;
  };

  for (int c = 0; c < size; ++c) {
    dfs3(dfs3, c);
  }

  // for (int c = 0; c < size; ++c) {
  //   cout << component_sizes[c] << " ";
  // }
  // cout << endl;

  vector<int> ans(n+1);
  for (int i = 1; i <= n; ++i) {
    int cid = cids[i];
    ans[i] = component_sizes[cid];
  }

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
