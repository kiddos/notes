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

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> visited(n+1);
  vector<int> prev(n+1);
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();

      for (int next_node : adj[node]) {
        if (visited[next_node]) {
          continue;
        }
        visited[next_node] = true;
        prev[next_node] = node;
        q.push(next_node);
      }
    }
  }

  if (!visited[n]) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int current_node = n;
  vector<int> ans = {n};
  while (current_node != 1) {
    current_node = prev[current_node];
    ans.push_back(current_node);
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << endl;
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
