#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // try to query 2 nodes at a time
  vector<int> ordering;
  auto dfs = [&](const auto& self, int node, int p) -> void {
    ordering.push_back(node);
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
    }
  };

  dfs(dfs, 1, 0);
  // straight dfs would work because
  // 1. if pair of node u,v is adjacent, then we can just query again to find the node
  // 2. if the pair forms a simple path, then all the nodes in the simple path has already been visited
  // we still just need to check one of u, v to get the node

  if (n % 2 == 1) {
    int size = n-1;
    for (int i = 0; i < size; i += 2) {
      int x = ordering[i];
      int y = ordering[i+1];
      int result = query(x, y);
      if (result) {
        if (query(x, x)) {
          answer(x);
        } else {
          answer(y);
        }
        return;
      }
    }
    answer(ordering.back());
  } else {
    for (int i = 0; i < n; i += 2) {
      int x = ordering[i];
      int y = ordering[i+1];
      int result = query(x, y);
      if (result) {
        if (query(x, x)) {
          answer(x);
        } else {
          answer(y);
        }
        return;
      }
    }
  }
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
