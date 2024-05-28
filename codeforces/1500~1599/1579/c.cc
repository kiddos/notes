#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  auto found_pattern = [&](int r, int c, int d) -> bool {
    if (grid[r][c] != '*') return false;
    for (int x = 0; x < d; ++x) {
      r++;
      c++;
      if (r >= n || c >= m) return false;
      if (grid[r][c] != '*') return false;
    }
    for (int x = 0; x < d; ++x) {
      r--;
      c++;
      if (r < 0 || c >= m) return false;
      if (grid[r][c] != '*') return false;
    }
    return true;
  };

  vector<vector<bool>> valid(n, vector<bool>(m));
  auto confirm_pattern = [&](int r, int c, int d) {
    valid[r][c] = true;
    for (int x = 0; x < d; ++x) {
      r++;
      c++;
      valid[r][c] = true;
    }
    for (int x = 0; x < d; ++x) {
      r--;
      c++;
      valid[r][c] = true;
    }
  };

  for (int d = k; d <= n; ++d) {
    int width = d * 2 + 1;
    int height = d;
    for (int i = 0; i <= n-height; ++i) {
      for (int j = 0; j <= m-width; ++j) {
        if (found_pattern(i, j, d)) {
          confirm_pattern(i, j, d);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '*' && !valid[i][j]) {
        cout << "NO" << endl;
        return;
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
