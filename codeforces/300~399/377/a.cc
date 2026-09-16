#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  auto find_first_empty = [&]() -> pair<int,int> {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '.') {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  };

  pair<int,int> first = find_first_empty();
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  auto compute_dist = [&](pair<int,int> start, vector<vector<int>>& dists) -> void {
    dists[start.first][start.second] = 0;
    queue<pair<int,int>> q;
    q.push(start);
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        auto [r, c] = q.front();
        q.pop();
        for (vector<int>& d : delta) {
          int r2 = r + d[0], c2 = c + d[1];
          if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) {
            continue;
          }
          if (s[r2][c2] == '#') {
            continue;
          }
          if (dists[r2][c2] >= 0) {
            continue;
          }
          dists[r2][c2] = dists[r][c] + 1;
          q.push({r2, c2});
        }
      }
    }
  };

  vector<vector<int>> d1(n, vector<int>(m, -1));
  compute_dist(first, d1);
  vector<array<int,3>> empty_cells;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      empty_cells.push_back({d1[i][j], i, j});
    }
  }
  sort(empty_cells.rbegin(), empty_cells.rend());
  for (int i = 0; i < k; ++i) {
    auto [d, r, c] = empty_cells[i];
    s[r][c] = 'X';
  }

  for (int i = 0; i < n; ++i) {
    cout << s[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
