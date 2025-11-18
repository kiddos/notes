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
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<FlowEdge> flow_edges;
  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{a, b, 1, 0});
    adj[b].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{b, a, 0, 0});

    adj[b].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{b, a, 1, 0});
    adj[a].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{a, b, 0, 0});
  }

  vector<int> level(n+1);
  auto bfs = [&]() -> bool {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(1);
    level[1] = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();

        for (int edge_idx : adj[node]) {
          auto [u, v, capacity, flow] = flow_edges[edge_idx];
          if (capacity - flow <= 0) {
            continue;
          }
          if (level[v] != -1) {
            continue;
          }
          level[v] = level[u] + 1;
          q.push(v);
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
      FlowEdge& e = flow_edges[edge_idx];
      if (level[e.v] != level[e.u] + 1) {
        continue;
      }

      i64 flow_left = min(e.capacity - e.flow, pushed);
      i64 flow = self(self, e.v, flow_left);
      if (flow == 0) {
        continue;
      }

      e.flow += flow;
      FlowEdge& e2 = flow_edges[edge_idx^1];
      e2.flow -= flow;
      return flow;
    }
    return 0;
  };

  while (true) {
    if (!bfs()) {
      break;
    }

    constexpr i64 inf = numeric_limits<i64>::max();
    fill(edge_indices.begin(), edge_indices.end(), 0);
    while (dfs(dfs, 1, inf));
  }

  // run bfs again
  // and the edge with 1 node level == -1 and 1 node level >= 0 is the edge to remove
  bfs();

  vector<pair<int,int>> ans;
  for (auto [a, b] : edges) {
    if ((level[a] < 0 && level[b] >= 0) || (level[a] >= 0 && level[b] < 0)) {
      ans.push_back({a, b});
    }
  }

  cout << ans.size() << endl;
  for (auto [u, v] : ans) {
    cout << u << " " << v << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
