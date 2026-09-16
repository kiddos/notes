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
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    edges.emplace_back(x, y);
  }
  
  DisjointSet ds(n+1);
  for (auto [x, y] : edges) {
    ds.join(x, y);
  }

  vector<vector<int>> group(n+1);
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    group[p].push_back(c[i]);
  }

  i64 ans = 0;
  for (int p = 1; p <= n; ++p) {
    if (group[p].empty()) {
      continue;
    }
    sort(group[p].begin(), group[p].end());
    ans += group[p][0];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
