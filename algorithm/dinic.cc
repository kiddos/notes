#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
  int u, v;
  ll capacity;
};

struct FlowEdge {
  int u, v;
  ll capacity, flow;
};

class Dinic {
 public:
  ll max_flow(int s, int t, int n, vector<Edge>& edges) {
    // 1. construct a level graph with bfs from source to nodes with capacity-flow > 0
    // 2. if the sink is never reached during bfs, stop and return the maximum flow
    // 3. do multiple dfs until a blocking flow is reached
    // a blocking flow of a graph is where all path from source to sink is saturated
    vector<vector<int>> adj(n);
    vector<FlowEdge> flow_edges;
    int m = 0;
    for (auto [u, v, capacity] : edges) {
      flow_edges.push_back(FlowEdge{u, v, capacity, 0});
      flow_edges.push_back(FlowEdge{v, u, 0, 0});
      adj[u].push_back(m);
      adj[v].push_back(m+1);
      m += 2;
    }

    vector<int> level(n);
    auto bfs = [&]() -> bool {
      fill(level.begin(), level.end(), -1);

      queue<int> q;
      q.push(s);
      level[s] = 0;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
          if (flow_edges[i].capacity - flow_edges[i].flow < 1) continue;
          if (level[flow_edges[i].v] != -1) continue;
          level[flow_edges[i].v] = level[flow_edges[i].u] + 1;
          q.push(flow_edges[i].v);
        }
      }
      return level[t] != -1;
    };

    vector<int> ptr(n);
    function<ll(int,ll)> dfs = [&](int node, ll pushed) -> ll {
      if (pushed == 0) return 0;
      if (node == t) return pushed;
      for (int& i = ptr[node]; i < adj[node].size(); ++i) {
        int j = adj[node][i];
        int next_node = flow_edges[j].v;
        ll flow_left = flow_edges[j].capacity - flow_edges[j].flow;
        if (level[node]+1 != level[next_node] || flow_left < 1)
          continue;
        ll result = dfs(next_node, min(pushed, flow_left));
        if (result == 0)
          continue;
        flow_edges[j].flow += result;
        flow_edges[j^1].flow -= result;
        return result;
      }
      return 0;
    };

    ll flow = 0;
    while (true) {
      if (!bfs()) {
        break;
      }
      fill(ptr.begin(), ptr.end(), 0);
      while (ll pushed = dfs(s, numeric_limits<int>::max())) {
        flow += pushed;
      }
    }
    return flow;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 11;

  vector<Edge> edges;
  edges.push_back(Edge{0, 1, 7});
  edges.push_back(Edge{0, 2, 2});
  edges.push_back(Edge{0, 3, 1});
  edges.push_back(Edge{1, 4, 2});
  edges.push_back(Edge{1, 5, 4});
  edges.push_back(Edge{2, 5, 5});
  edges.push_back(Edge{2, 6, 6});
  edges.push_back(Edge{3, 4, 4});
  edges.push_back(Edge{3, 8, 8});
  edges.push_back(Edge{4, 7, 7});
  edges.push_back(Edge{4, 8, 1});
  edges.push_back(Edge{5, 7, 3});
  edges.push_back(Edge{5, 9, 3});
  edges.push_back(Edge{6, 9, 3});
  edges.push_back(Edge{7, 10, 1});
  edges.push_back(Edge{8, 10, 2});
  edges.push_back(Edge{9, 10, 4});

  int max_flow = Dinic().max_flow(0, 10, n, edges);
  cout << "max flow: " << max_flow << endl;
  return 0;
}
