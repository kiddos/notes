#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  int find(int x) {
    if (x != parent_[x]) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
  }

 private:
  vector<int> parent_, rank_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<unordered_set<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].insert(v);
    adj[v].insert(u);
  }

  vector<array<int,3>> ans;

  auto toggle_edge = [&](int u, int v) {
    if (adj[u].count(v)) {
      adj[u].erase(v);
    } else {
      adj[u].insert(v);
    }
  };

  auto perform_op = [&](int a, int b, int c) {
    toggle_edge(a, b);
    toggle_edge(b, a);
    toggle_edge(a, c);
    toggle_edge(c, a);
    toggle_edge(b, c);
    toggle_edge(c, b);
    ans.push_back({a, b, c});
  };

  for (int a = 1; a <= n; ++a) {
    while (adj[a].size() >= 2) {
      int b = *adj[a].begin();
      int c = *next(adj[a].begin());
      perform_op(a, b, c);
    }
  }

  set<pair<int,int>> edge_set;
  for (int u = 1; u <= n; ++u) {
    for (int v : adj[u]) {
      edge_set.insert({min(u, v), max(u, v)});
    }
  }

  if (!edge_set.empty()) {
    DisjointSet ds(n+1);
    for (auto [u, v] : edge_set) {
      ds.join(u, v);
    }

    unordered_map<int,vector<int>> roots;
    for (int node = 1; node <= n; ++node) {
      int p = ds.find(node);
      roots[p].push_back(node);
    }

    if (roots.size() > 1) {
      // pick an edge
      // and use that to join the other roots
      auto edge = *edge_set.begin();
      int a = edge.first, b = edge.second;
      int current_root = ds.find(a);
      for (auto [root, nodes] : roots) {
        assert(nodes.size() <= 2);
        // cout << "root=" << root << endl;
        if (root == current_root) {
          continue;
        }

        ans.push_back({a, b, root});
        b = root;
      }
    }
  }

  cout << ans.size() << endl;
  for (auto [a, b, c] : ans) {
    cout << a << " " << b << " " << c << endl;
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
