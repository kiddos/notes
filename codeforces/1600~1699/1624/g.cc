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

int kruskal(int n, vector<array<int,3>>& edges, int ignore) {
  DisjointSet ds(n+1);

  int ans = 0;
  for (auto [u, v, w] : edges) {
    if (w & ignore) {
      continue;
    }

    if (ds.join(u, v)) {
      ans |= w;
    }
  }

  int p0 = ds.find(1);
  for (int node = 2; node <= n; ++node) {
    int p = ds.find(node);
    if (p != p0) {
      return -1;
    }
  }
  return ans;
}

void solve() {
  string empty;
  getline(cin, empty);

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

  int ignore = 0;
  for (int b = 31; b >= 0; --b) {
    int result = kruskal(n, edges, ignore | (1<<b));
    if (result >= 0) {
      ignore |= (1<<b);
    }
  }
  int ans = kruskal(n, edges, ignore);
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
