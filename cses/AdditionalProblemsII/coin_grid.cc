#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// imagine each row is a node, and each column also represent a node
// a source node connect to the row nodes,
// and sink node connects to the column nodes, each with capacity 1
// and if there is a coin on the grid,
// connect the row and column the capacity infinity
//
// this becomes a minimum cut problem

struct FlowEdge {
  int u, v;
  i64 capacity, flow;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int source = 0, sink = 2 * n + 1;
  vector<FlowEdge> flow_edges;
  vector<vector<int>> adj(2 * n + 2);
  for (int i = 0; i < n; ++i) {
    int u = source, v = i+1;
    adj[u].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{u, v, 1, 0});
    adj[v].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{v, u, 0, 0});
  }

  for (int j = 0; j < n; ++j) {
    int u = j+1 + n, v = sink;
    adj[u].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{u, v, 1, 0});
    adj[v].push_back(flow_edges.size());
    flow_edges.push_back(FlowEdge{v, u, 0, 0});
  }

  constexpr i64 inf = 1e18;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'o') {
        int u = i+1;
        int v = j+1+n;
        adj[u].push_back(flow_edges.size());
        flow_edges.push_back(FlowEdge{u, v, inf, 0});
        adj[v].push_back(flow_edges.size());
        flow_edges.push_back(FlowEdge{v, u, 0, 0});
      }
    }
  }

  vector<int> level(2 * n + 2);
  auto bfs = [&]() -> bool {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(0);
    level[0] = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();

        for (int edge_idx : adj[node]) {
          auto [u, v, capacity, flow] = flow_edges[edge_idx];
          if (level[v] != -1) {
            continue;
          }
          if (capacity - flow <= 0) {
            continue;
          }
          level[v] = level[u] + 1;
          q.push(v);
        }
      }
    }
    return level[sink] != -1;
  };

  vector<int> edge_indices(2 * n + 2);
  auto dfs = [&](const auto& self, int node, i64 pushed) -> i64 {
    if (pushed == 0) {
      return 0;
    }
    if (node == sink) {
      return pushed;
    }

    for (int& p = edge_indices[node]; p < (int)adj[node].size(); ++p) {
      int edge_idx = adj[node][p];
      FlowEdge& e = flow_edges[edge_idx];
      if (level[e.v] != level[e.u] + 1) {
        continue;
      }
      i64 flow_left = min(pushed, e.capacity - e.flow);
      if (flow_left <= 0) {
        continue;
      }
      i64 flow = self(self, e.v, flow_left);
      if (flow <= 0) {
        continue;
      }

      e.flow += flow;
      FlowEdge& e2 = flow_edges[edge_idx ^ 1];
      e2.flow -= flow;

      return flow;
    }
    return 0;
  };

  while (true) {
    if (!bfs()) {
      break;
    }

    fill(edge_indices.begin(), edge_indices.end(), 0);
    while (dfs(dfs, 0, inf));
  }

  bfs();

  vector<pair<int,int>> ans;
  for (int r = 0; r < n; ++r) {
    int u = source, v = r+1;
    if (level[u] >= 0 && level[v] < 0) {
      ans.push_back({1, r+1});
    }
  }
  for (int c = 0; c < n; ++c) {
    int u = c+1 + n, v = sink;
    if (level[u] >= 0 && level[v] < 0) {
      ans.push_back({2, c+1});
    }
  }

  cout << ans.size() << endl;
  for (auto [t, idx] : ans) {
    cout << t << " " << idx << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
