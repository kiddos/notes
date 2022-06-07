#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
  int a, b;
  ll c;
};

ll solve(int s, int t, int n, vector<Edge>& edges) {
  vector<unordered_set<int>> adj(n);
  vector<vector<ll>> capacity(n, vector<ll>(n));
  for (auto [a, b, c] : edges) {
    adj[a].insert(b);
    adj[b].insert(a);
    capacity[a][b] += c;
  }

  vector<int> parent(n);
  auto bfs = [&](int s, int t) -> ll {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,ll>> q;
    q.push({s, numeric_limits<ll>::max()});

    while (!q.empty()) {
      int node = q.front().first;
      ll flow = q.front().second;
      q.pop();
      for (int next_node : adj[node]) {
        if (parent[next_node] == -1 && capacity[node][next_node]) {
          parent[next_node] = node;
          ll new_flow = min(flow, capacity[node][next_node]);
          if (next_node == t) {
            return new_flow;
          }
          q.push({next_node, new_flow});
        }
      }
    }
    return 0LL;
  };

  ll ans = 0;
  ll flow = 0;
  while ((flow = bfs(s, t))) {
    ans += flow;
    int node = t;
    while (node != s) {
      int p = parent[node];
      capacity[p][node] -= flow;
      capacity[node][p] += flow;
      node = p;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    ll c = 0;
    cin >> a >> b >> c;
    edges.push_back(Edge{a-1, b-1, c});
  }

  ll ans = solve(0, n-1, n, edges);
  cout << ans << endl;
  return 0;
}
