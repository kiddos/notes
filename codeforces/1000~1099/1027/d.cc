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
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> rev(n+1);
  for (int i = 1; i <= n; ++i) {
    rev[a[i]].push_back(i);
  }

  vector<bool> visited(n+1);
  vector<int> order;
  auto dfs1 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    self(self, a[node]);
    order.push_back(node);
  };

  for (int node = 1; node <= n; ++node) {
    dfs1(dfs1, node);
  }

  reverse(order.begin(), order.end());

  fill(visited.begin(), visited.end(), false);
  vector<int> component;
  auto dfs2 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    component.push_back(node);
    for (int prev_node : rev[node]) {
      self(self, prev_node);
    }
  };

  vector<vector<int>> components;
  for (int node : order) {
    component.clear();
    dfs2(dfs2, node);
    if (!component.empty()) {
      components.push_back(component);
    }
  }

  int size = components.size();
  // for (int id = 0; id < size; ++id) {
  //   cout << "component: ";
  //   for (int node : components[id]) {
  //     cout << node << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> component_id(n+1);
  for (int id = 0; id < size; ++id) {
    for (int node : components[id]) {
      component_id[node] = id;
    }
  }

  vector<int> outgoing(size);
  for (int id = 0; id < size; ++id) {
    for (int node : components[id]) {
      int next_node = a[node];
      int next_id = component_id[next_node];
      if (next_id != id) {
        outgoing[id]++;
      }
    }
  }

  i64 ans = 0;
  for (int id = 0; id < size; ++id) {
    if (outgoing[id] == 0) {
      int min_cost = numeric_limits<int>::max();
      for (int node : components[id]) {
        min_cost = min(min_cost, c[node]);
      }
      ans += min_cost;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
