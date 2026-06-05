#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<bool>> grid(n, vector<bool>(m));

  auto is_black = [&](int r, int c) -> bool {
    if (r < 0 || c < 0 || r+1 >= n || c+1 >= m) {
      return false;
    }
    return grid[r][c] && grid[r][c+1] && grid[r+1][c] && grid[r+1][c+1];
  };

  int ans = 0;
  for (int t = 1; t <= k; ++t) {
    int i = 0, j = 0;
    cin >> i >> j;
    i--;
    j--;
    grid[i][j] = true;
    if (is_black(i, j) || is_black(i-1, j-1) || is_black(i-1, j) || is_black(i, j-1)) {
      if (!ans) {
        ans = t;
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
