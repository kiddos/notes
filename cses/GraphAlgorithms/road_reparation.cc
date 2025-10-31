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
  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
    return e1[2] < e2[2];
  });

  DisjointSet ds(n+1);
  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    auto [a, b, c] = edges[i];
    if (ds.join(a, b)) {
      ans += c;
    }
  }

  int p0 = ds.find(1);
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    if (p != p0) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
