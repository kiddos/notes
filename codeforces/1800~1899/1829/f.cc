#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> indegree(n);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    indegree[u]++;
    indegree[v]++;
  }

  queue<int> q;
  vector<bool> visited(n);
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 1) {
      q.push(i);
      visited[i] = true;
    }
  }

  vector<int> sizes;
  while (!q.empty()) {
    sizes.push_back(q.size());
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      
      for (int next_node : adj[node]) if (!visited[next_node]) {
        q.push(next_node);
        visited[next_node] = true;
      }
    }
  }

  assert(sizes.size() == 3);
  assert(sizes[2] == 1);

  int x = sizes[1];
  int y = sizes[0] / x;
  cout << x << " " << y << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
