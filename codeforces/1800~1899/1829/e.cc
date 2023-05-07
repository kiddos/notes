#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<bool>> visited(n, vector<bool>(m));
  function<int(int,int)> dfs = [&](int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return 0;
    if (grid[r][c] == 0) return 0;
    if (visited[r][c]) return 0;
    visited[r][c] = true;

    return dfs(r+1, c) + dfs(r, c+1) + dfs(r-1, c) + dfs(r, c-1) + grid[r][c];
  };
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j] && grid[i][j]) {
        ans = max(ans, dfs(i, j));
      }
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
