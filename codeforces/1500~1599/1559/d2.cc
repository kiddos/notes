#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  DisjointSet(const DisjointSet& ds) {
    parent_ = ds.parent_;
    rank_ = ds.rank_;
  }

  DisjointSet& operator=(const DisjointSet& ds) {
    parent_ = ds.parent_;
    rank_ = ds.rank_;
    return *this;
  }

  int find(int x) {
    if (x != parent_[x]) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  bool same_group(int x, int y) {
    return find(x) == find(y);
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return;
    }

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
  int n = 0, m1 = 0, m2 = 0;
  cin >> n >> m1 >> m2;

  DisjointSet ds1(n+1), ds2(n+1);
  for (int i = 0; i < m1; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    ds1.join(u, v);
  }
  for (int i = 0; i < m2; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    ds2.join(u, v);
  }

  vector<pair<int,int>> ans;

  int edge_count = max(m1, m2);
  for (int node = 2; node <= n; ++node) {
    if (!ds1.same_group(1, node) && !ds2.same_group(1, node)) {
      ds1.join(1, node);
      ds2.join(1, node);
      ans.emplace_back(1, node);
      edge_count++;
    } 
  }
  for (int node1 = 2, node2 = 1; edge_count != n-1; ++node1) {
    if (ds1.same_group(1, node1)) {
      continue;
    }
    while (node2 <= n && ds2.same_group(1, node2)) {
      node2++;
    }
    ds1.join(1, node1);
    ds2.join(1, node2);
    edge_count++;
    ans.emplace_back(node1, node2);
  }

  cout << ans.size() << endl;
  for (auto& [u, v] : ans) {
    cout << u << " " << v << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
