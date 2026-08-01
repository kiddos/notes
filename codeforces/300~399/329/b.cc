#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  pair<int,int> start, end;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'S') {
        start = {i, j};
      }
      if (grid[i][j] == 'E') {
        end = {i, j};
      }
    }
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  auto compute_dist = [&](vector<vector<int>>& dists) -> void {
    queue<pair<int,int>> q;
    q.push(end);
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[end.first][end.second] = true;

    int step = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        auto [r, c] = q.front();
        q.pop();
        dists[r][c] = step;
        for (vector<int>& d : delta) {
          int r2 = r + d[0], c2 = c + d[1];
          if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) {
            continue;
          }
          if (grid[r2][c2] == 'T') {
            continue;
          }
          if (visited[r2][c2]) {
            continue;
          }
          visited[r2][c2] = true;
          q.push({r2, c2});
        }
      }
      step++;
    }
  };

  constexpr int inf = 1e9;
  vector<vector<int>> dists(n, vector<int>(m, inf));
  compute_dist(dists);
  int player_dist = dists[start.first][start.second];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (isdigit(grid[i][j]) && dists[i][j] <= player_dist) {
        int battle = grid[i][j] - '0';
        ans += battle;
      }
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
