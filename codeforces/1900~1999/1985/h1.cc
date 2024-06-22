#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  vector<vector<int>> ids(n, vector<int>(m));
  function<int(int,int,int)> dfs = [&](int r, int c, int id) -> int {
    if (r < 0 || r >= n || c < 0 || c >= m) return 0;
    if (grid[r][c] != '#') return 0;
    if (ids[r][c]) return 0;
    ids[r][c] = id;
    return dfs(r+1, c, id) + dfs(r, c+1, id) + dfs(r-1, c, id) + dfs(r, c-1, id) + 1;
  };

  int ans = 0;
  vector<int> sizes = {0};
  int id = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        int result = dfs(i, j, id);
        sizes.push_back(result);
        id++;

        ans = max(ans, result);
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    int count = 0;
    set<int> found;
    for (int i = 0; i < n; ++i) {
      count += grid[i][j] == '#';
      found.insert(ids[i][j]);
      if (j > 0 && grid[i][j-1] == '#') {
        found.insert(ids[i][j-1]);
      }
      if (j+1 < m && grid[i][j+1] == '#') {
        found.insert(ids[i][j+1]);
      }
    }
    int size = n - count;
    for (int id : found) {
      size += sizes[id];
    }
    ans = max(ans, size);
  }

  for (int i = 0; i < n; ++i) {
    int count = 0;
    set<int> found;
    for (int j = 0; j < m; ++j) {
      count += grid[i][j] == '#';
      found.insert(ids[i][j]);
      if (i > 0 && grid[i-1][j] == '#') {
        found.insert(ids[i-1][j]);
      }
      if (i+1 < n && grid[i+1][j] == '#') {
        found.insert(ids[i+1][j]);
      }
    }
    int size = m - count;
    for (int id : found) {
      size += sizes[id];
    }
    ans = max(ans, size);
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
