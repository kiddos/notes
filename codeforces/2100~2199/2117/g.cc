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
  int n = 0, m = 0;
  cin >> n >> m;
  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
    return e1[2] < e2[2];
  });

  DisjointSet ds(n+1);
  int ans = edges.back()[2] * 2;
  constexpr int inf = 1e9;
  vector<int> min_w(n+1, inf);
  for (int i = 0; i < m; ++i) {
    auto [u, v, w] = edges[i];
    int pu = ds.find(u), pv = ds.find(v);
    ds.join(u, v);
    int p = ds.find(u);
    min_w[p] = min({min_w[pu], min_w[pv], w});
    int p1 = ds.find(1), pn = ds.find(n);
    if (p1 == pn) {
      int total = w + min_w[p1];
      ans = min(ans, total);
    }
  }
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
