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

  vector<int> state(n+1);
  vector<int> time(n+1);
  vector<int> parent(n+1);

  vector<int> cycle;

  auto construct = [&](int current, int start) -> void {
    if (cycle.size()) {
      return;
    }
    cycle = {start};
    int iter = n;
    while (current != start && iter-- > 0) {
      cycle.push_back(current);
      current = parent[current];
    }
  };

  auto dfs = [&](const auto& self, int node, int p, int t) -> void {
    state[node] = 1;
    time[node] = t;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      if (state[next_node] == 1) {
        int p1 = time[next_node] % 2;
        int p2 = (t+1) % 2;
        if (p1 != p2) {
          construct(node, next_node);
        }
      } else if (!state[next_node]) {
        parent[next_node] = node;
        self(self, next_node, node, t+1);
      }
    }
    state[node] = 2;
  };

  dfs(dfs, 1, 1, 1);

  if (cycle.empty()) {
    cout << "-1" << endl;
    return;
  }

  cout << cycle.size() << endl;
  for (int node : cycle) {
    cout << node << " ";
  }
  cout << endl;
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
