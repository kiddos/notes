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
  auto dfs1 = [&](const auto& self, int node) -> void {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj1[node]) {
      self(self, next_node);
    }
  };

  dfs1(dfs1, 1);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cout << "NO" << endl;
      cout << "1 " << i << endl;
      return;
    }
  }

  queue<int> q;
  q.push(1);
  fill(visited.begin(), visited.end(), false);
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

  for (int i = 2; i <= n; ++i) {
    if (!visited[i]) {
      cout << "NO" << endl;
      cout << i << " 1" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
