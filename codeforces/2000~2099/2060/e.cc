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
  int n = 0, m1 = 0, m2 = 0;
  cin >> n >> m1 >> m2;
  vector<pair<int,int>> f, g;
  for (int i = 0; i < m1; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    f.emplace_back(u, v);
  }
  for (int i = 0; i < m2; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    g.emplace_back(u, v);
  }

  DisjointSet g_ds(n+1);
  for (auto [u, v] : g) {
    g_ds.join(u, v);
  }

  int remove = 0;
  DisjointSet f_ds(n+1);
  for (auto [u, v] : f) {
    int pu = g_ds.find(u), pv = g_ds.find(v);
    if (pu == pv) {
      f_ds.join(u, v);
    } else {
      remove++;
    }
  }

  unordered_map<int, vector<int>> g_group(n+1);
  for (int node = 1; node <= n; ++node) {
    int p = g_ds.find(node);
    g_group[p].push_back(node);
  }

  int add = 0;
  for (auto [p, nodes] : g_group) {
    unordered_set<int> f_groups;
    for (int node : nodes) {
      int p = f_ds.find(node);
      f_groups.insert(p);
    }
    int size = f_groups.size();
    add += (size-1);
  }

  int ans = add + remove;
  cout << ans << endl;
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
