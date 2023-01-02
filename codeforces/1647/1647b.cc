#include <bits/stdc++.h>

using namespace std;

bool solve(vector<string>& grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> bot(n, vector<int>(m));
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '1') {
        bot[i][j] = (i+1 < n ? bot[i+1][j] : 0) + 1;
      }
    }
  }

  vector<vector<int>> top(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '1') {
        top[i][j] = (i-1 >= 0 ? top[i-1][j] : 0) + 1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (bot[i][j] || top[i][j]) {
        int k = j+1;
        while (k < m && (bot[i][k] || top[i][k])) {
          if (bot[i][k] != bot[i][j] || top[i][k] != top[i][j]) return false;
          k++;
        }
        j = k-1;
      }
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    bool ans = solve(grid);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout.flush();
  return 0;
}
