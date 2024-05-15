#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<vector<array<i64,2>>> dp(n, vector<array<i64,2>>(m, {0, 0}));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i > 0) {
        dp[i][j][0] = dp[i-1][j][1] + 1;
      }
      if (j > 0) {
        dp[i][j][1] = dp[i][j-1][0] + 1;
      }
    }
  }

  i64 paths = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      paths += dp[i][j][0];
      paths += dp[i][j][1];
      // cout << "(" << dp[i][j][0] << "," << dp[i][j][1] << ")  ";
    }
    // cout << endl;
  }

  i64 total_free = n * m;

  vector<vector<bool>> free(n, vector<bool>(m, true));
  auto type1 = [&](int x, int y, int change) {
    int r = x, c = y;
    int right = 0;
    // go down first and then right
    while (true) {
      if (++r >= n || !free[r][c]) break;
      right++;
      if (++c >= m || !free[r][c]) break;
      right++;
    }
    r = x, c = y;
    i64 left = 0;
    while (true) {
      // go left first and then top
      if (--c < 0 || !free[r][c]) break;
      left++;
      if (--r < 0 || !free[r][c]) break;
      left++;
    }
    i64 total = (left + 1) * (right + 1) - 1;
    paths += change * total;
  };

  auto type2 = [&](int x, int y, int change) {
    int r = x, c = y;
    // go right first and then down
    i64 right = 0;
    while (true) {
      if (++c >= m || !free[r][c]) break;
      right++;
      if (++r >= n || !free[r][c]) break;
      right++;
    }
    r = x, c = y;
    i64 left = 0;
    while (true) {
      // go up first and then left
      if (--r < 0 || !free[r][c]) break;
      left++;
      if (--c < 0 || !free[r][c]) break;
      left++;
    }
    i64 total = (left + 1) * (right + 1) - 1;
    paths += change * total;
  };

  // cout << "total free=" << total_free << ", path=" << paths << endl;

  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    x--;
    y--;

    if (free[x][y]) {
      type1(x, y, -1);
      type2(x, y, -1);

      free[x][y] = false;
      total_free--;

      i64 ans = paths + total_free;
      cout << ans << endl;
    } else {
      type1(x, y, 1);
      type2(x, y, 1);


      free[x][y] = true;
      total_free++;

      i64 ans = paths + total_free;
      cout << ans << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
