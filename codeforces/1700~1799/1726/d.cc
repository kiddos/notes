#include <bits/stdc++.h>

using namespace std;

bool has_cycle(const unordered_map<int,int>& components) {
  if (components.size() != 3) return false;

  for (auto& [node, count] : components) {
    if (count != 2) return false;
  }
  return true;
}

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
    if (px == py) return false;
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
  // we want to form 2 spanning tree
  // but m could be n+2
  // so there could be a cycle with 3 edges

  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;

  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  DisjointSet ds(n+1);

  vector<bool> used(m);
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    if (ds.join(u, v)) {
      used[i] = true;
    }
  }

  string ans(m, '0');
  for (int i = 0; i < m; ++i) if (used[i]) {
    ans[i] = '1';
  }

  unordered_map<int, int> components;
  for (int i = 0; i < m; ++i) if (!used[i]) {
    auto [u, v] = edges[i];
    components[u]++;
    components[v]++;
  }

  // if the other graph has a cycle
  // the cycle should be a triangle
  if (has_cycle(components) && m == n+2) {
    // we want to remove 1 edge from this cycle
    // and add it to the other graph
    // and move all edges from other graph that is connected to 1 of the node of this edge
    // and we won't get a cycle
    for (int i = 0; i < m; ++i) if (!used[i]) {
      auto [u, v] = edges[i];
      ans[i] = '1';

      for (int j = 0; j < m; ++j) if (used[j]) {
        auto [u2, v2] = edges[j];
        if (u2 == u || v2 == u) {
          ans[j] = '0';
        }
      }

      cout << ans << endl;
      return;
    }
  } else {
    cout << ans << endl;
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
