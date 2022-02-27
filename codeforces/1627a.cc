#include <bits/stdc++.h>

using namespace std;

int solve(vector<string>& grid, int r, int c) {
  if (grid[r][c] == 'B') return 0;

  int n = grid.size(), m = grid[0].size();
  function<bool(void)> all_white = [&]() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'B') return false;
      }
    }
    return true;
  };

  if (all_white()) return -1;

  for (int i = 0; i < n; ++i) {
    if (grid[i][c] == 'B') return 1;
  }
  for (int j = 0; j < m; ++j) {
    if (grid[r][j] == 'B') return 1;
  }
  return 2;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0, r = 0, c = 0;
    cin >> n >> m >> r >> c;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    int ans = solve(grid, r-1, c-1);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
