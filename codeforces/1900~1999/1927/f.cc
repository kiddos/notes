#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  bool join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return false;
    }
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
    return true;
  }

 private:
  vector<int> parent_, rank_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<array<int,3>> edges;
  for (int i = 0; i < m ; ++i) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
    return e1[2] > e2[2];
  });

  vector<vector<int>> adj(n+1);
  vector<int> degree(n+1);
  DisjointSet ds(n+1);
  int min_w = numeric_limits<int>::max();
  int start = 0, end = 0;
  for (auto& [u, v, w] : edges) {
    if (ds.join(u, v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      degree[u]++;
      degree[v]++;
    } else {
      // found a cycle
      min_w = w;
      start = u;
      end = v;
    }
  }

  vector<int> path = {start};
  function<bool(int,int)> dfs = [&](int node, int p) -> bool {
    if (node == end) {
      return true;
    }
    for (int next_node : adj[node]) if (next_node != p) {
      path.push_back(next_node);
      if (dfs(next_node, node)) return true;
      path.pop_back();
    }
    return false;
  };

  dfs(start, -1);

  cout << min_w << " " << path.size() << endl;
  for (int node : path) cout << node << " ";
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
