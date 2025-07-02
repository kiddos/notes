#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int r = 0, c = 0, n = 0, p = 0;
  cin >> r >> c >> n >> p;
  vector<vector<int>> G(r, vector<int>(c));
  pair<int,int> start;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> G[i][j];
      if (G[i][j] == p) {
        start = {i, j};
      }
    }
  }

  pair<int,int> coord = start;
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  set<int> s;
  for (int id = p, t = 0; id >= 1; --id, ++t) {
    auto [i, j] = coord;
    pair<int,int> next_coord;

    for (vector<int>& d : delta) {
      int i2 = i + d[0], j2 = j + d[1];
      if (i2 < 0 || i2 >= r || j2 < 0 || j2 >= c) {
        continue;
      }

      if (G[i2][j2] > 0) {
        int id_at_t = G[i2][j2] + t;
        if (id_at_t <= n) {
          s.insert(id_at_t);
        }
      }

      if (G[i2][j2] == id-1) {
        next_coord = {i2, j2};
      }
    }
    coord = std::move(next_coord);
  }

  cout << s.size() << "/" << n-1 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
