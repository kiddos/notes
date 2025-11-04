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

  vector<vector<pair<int,int>>> adj1(n+1);
  vector<vector<int>> adj2(n+1);
  for (auto [a, b, c] : edges) {
    adj1[a].push_back({b, c});
    adj2[b].push_back(a);
  }

  constexpr i64 inf = 1e18;
  vector<i64> dists(n+1, inf);
  dists[1] = 0;
  // bellman ford
  for (int i = 0; i < m; ++i) {
    for (auto [a, b, c] : edges) {
      if (dists[a] < inf && dists[a] - c < dists[b]) {
        dists[b] = dists[a] - c;
      }
    }
  }
  vector<bool> marked(n+1);
  for (auto [a, b, c] : edges) {
    if (dists[a] < inf && dists[a] - c < dists[b]) {
      marked[b] = true;
    }
  }

  vector<bool> visited(n+1);
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      for (int prev_node : adj2[node]) {
        if (visited[prev_node]) {
          continue;
        }
        visited[prev_node] = true;
        q.push(prev_node);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (visited[i] && marked[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  i64 ans = -dists[n];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
