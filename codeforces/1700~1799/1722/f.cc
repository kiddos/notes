#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<vector<bool>> visited(n, vector<bool>(m));
  vector<vector<int>> delta1 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  function<int(int,int)> dfs = [&](int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return 0;
    if (grid[r][c] == '.') return 0;
    if (visited[r][c]) return 0;
    visited[r][c] = true;
    int count = 1;
    for (vector<int>& d : delta1) {
      int r2 = r + d[0], c2 = c + d[1];
      count += dfs(r2, c2);
    }
    return count;
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '*' && !visited[i][j]) {
        int shaded = dfs(i, j);
        // cout << shaded << ": " << i << ", " << j << endl;
        if (shaded != 3) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m-2; ++j) {
      if (visited[i][j] && visited[i][j+1] && visited[i][j+2]) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visited[i][j] && visited[i+1][j] && visited[i+2][j]) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  vector<vector<int>> delta2 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  vector<vector<bool>> marked(n, vector<bool>(m));
  function<bool(int,int)> find = [&](int r, int c) -> bool {
    if (r < 0 || r >= n || c < 0 || c >= m) return false;
    if (grid[r][c] == '.') return false;
    for (vector<int>& d : delta2) {
      int r2 = r + d[0], c2 = c + d[1];
      if (r2 < 0 || c2 < 0 || r2 >= n || c2 >= m) continue;
      if (marked[r2][c2]) continue;
      if (grid[r2][c2] == '*') return true;
    }
    return false;
  };

  auto count_shaded = [&](int i, int j) -> int {
    return (grid[i][j] == '*') + (grid[i][j-1] == '*') + (grid[i-1][j] == '*') + (grid[i-1][j-1] == '*');
  };

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      int shaded = count_shaded(i, j);
      if (shaded == 3) {
        marked[i-1][j-1] = marked[i][j-1] = marked[i-1][j] = marked[i][j] = true;
        if (find(i, j) || find(i-1, j) || find(i, j-1) || find(i-1, j-1)) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  cout << "YES" << endl;
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
