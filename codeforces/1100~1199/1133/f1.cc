#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (x != parent_[x]) {
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
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  vector<int> degrees(n+1);
  for (auto [u, v] : edges) {
    degrees[u]++;
    degrees[v]++;
  }
  int max_degree_node = max_element(degrees.begin(), degrees.end()) - degrees.begin();
  DisjointSet ds(n+1);
  vector<pair<int,int>> ans;
  for (auto [u, v] : edges) {
    if (u == max_degree_node || v == max_degree_node) {
      if (ds.join(u, v)) {
        ans.push_back({u, v});
      }
    }
  }

  for (auto [u, v] : edges) {
    if (ds.join(u, v)) {
      ans.push_back({u, v});
    }
  }

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
