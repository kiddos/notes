#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  vector<vector<pair<int,int>>> adj(n+1);
  vector<int> indegree(n+1);
  for (auto [a, b, c] : edges) {
    adj[a].push_back({b, c});
    indegree[b]++;
  }

  constexpr i64 inf = 1e18;
  vector<i64> dists(n+1, inf);

  vector<bool> visited(n+1);
  auto dfs = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (auto [next_node, w] : adj[node]) {
      self(self, next_node);
    }
  };

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dists[i] = 0;
      dfs(dfs, i);
    }
  }

  // bellman ford
  vector<int> prev(n+1);
  for (int i = 0; i < m; ++i) {
    for (auto [a, b, c] : edges) {
      if (dists[a] < inf && dists[a] + c < dists[b]) {
        prev[b] = a;
        dists[b] = dists[a] + c;
      }
    }
  }

  int start = -1;
  for (auto [a, b, c] : edges) {
    if (dists[a] < inf && dists[a] + c < dists[b]) {
      start = a;
    }
  }

  if (start < 0) {
    cout << "NO" << endl;
    return;
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << prev[i] << " ";
  // }
  // cout << endl;

  vector<bool> found(n+1);
  int current = start;
  deque<int> ans = {current};
  do {
    found[current] = true;
    current = prev[current];
    ans.push_back(current);
  } while (!found[current]);
  while (ans.front() != ans.back()) {
    ans.pop_front();
  }

  reverse(ans.begin(), ans.end());

  cout << "YES" << endl;
  for (int node : ans) {
    cout << node << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
