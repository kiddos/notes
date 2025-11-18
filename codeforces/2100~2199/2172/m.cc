#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  vector<bool> visited(n+1);
  visited[1] = true;
  int step = 0;
  vector<int> dist(k+1);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      dist[a[node]] = max(dist[a[node]], step);
      for (int next_node : adj[node]) {
        if (visited[next_node]) {
          continue;
        }
        q.push(next_node);
        visited[next_node] = true;
      }
    }
    step++;
  }

  for (int i = 1; i <= k; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
