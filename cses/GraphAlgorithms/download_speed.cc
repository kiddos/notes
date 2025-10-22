#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct FlowEdge {
  int u, v;
  i64 capacity, flow;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<FlowEdge> edges;
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    adj[a].push_back(edges.size());
    edges.push_back(FlowEdge{a, b, c, 0});
    adj[b].push_back(edges.size());
    edges.push_back(FlowEdge{b, a, 0, 0});
  }

  // dinic
  vector<int> level(n+1);
  auto bfs = [&]() -> bool {
    fill(level.begin(), level.end(), -1);
    level[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();
        for (int edge_idx : adj[node]) {
          FlowEdge& e = edges[edge_idx];
          if (e.capacity == e.flow) {
            continue;
          }
          if (level[e.v] != -1) {
            continue;
          }
          level[e.v] = level[node] + 1;
          q.push(e.v);
        }
      }
    }
    return level[n] != -1;
  };

  vector<int> edge_indices(n+1);
  auto dfs = [&](const auto& self, int node, i64 pushed) -> i64 {
    if (pushed == 0) {
      return 0;
    }
    if (node == n) {
      return pushed;
    }
    for (int& p = edge_indices[node]; p < (int)adj[node].size(); ++p) {
      int edge_idx = adj[node][p];
      FlowEdge& e = edges[edge_idx];
      if (level[e.v] != level[node] + 1) {
        continue;
      }
      i64 flow_left = min(pushed, e.capacity - e.flow);
      i64 flow = self(self, e.v, flow_left);
      if (flow == 0) {
        continue;
      }

      e.flow += flow;
      FlowEdge& e2 = edges[edge_idx^1];
      e2.flow -= flow;
      return flow;
    }
    return 0;
  };

  i64 max_flow = 0;
  while (true) {
    if (!bfs()) {
      break;
    }

    fill(edge_indices.begin(), edge_indices.end(), 0);
    while (i64 flow = dfs(dfs, 1, numeric_limits<i64>::max())) {
      max_flow += flow;
    }
  }

  cout << max_flow << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
