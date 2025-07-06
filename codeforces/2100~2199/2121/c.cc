#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> top_left(n, vector<int>(m));
  vector<vector<int>> top_right(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      top_left[i][j] = a[i][j];
      if (i > 0) {
        top_left[i][j] = max(top_left[i][j], top_left[i-1][j]);
      }
      if (j > 0) {
        top_left[i][j] = max(top_left[i][j], top_left[i][j-1]);
      }
    }

    for (int j = m-1; j >= 0; --j) {
      top_right[i][j] = a[i][j];
      if (i > 0) {
        top_right[i][j] = max(top_right[i][j], top_right[i-1][j]);
      }
      if (j+1 < m) {
        top_right[i][j] = max(top_right[i][j], top_right[i][j+1]);
      }
    }
  }

  vector<vector<int>> bot_left(n, vector<int>(m));
  vector<vector<int>> bot_right(n, vector<int>(m));
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      bot_left[i][j] = a[i][j];
      if (i+1 < n) {
        bot_left[i][j] = max(bot_left[i][j], bot_left[i+1][j]);
      }
      if (j > 0) {
        bot_left[i][j] = max(bot_left[i][j], bot_left[i][j-1]);
      }
    }

    for (int j = m-1; j >= 0; --j) {
      bot_right[i][j] = a[i][j];
      if (i+1 < n) {
        bot_right[i][j] = max(bot_right[i][j], bot_right[i+1][j]);
      }
      if (j+1 < m) {
        bot_right[i][j] = max(bot_right[i][j], bot_right[i][j+1]);
      }
    }
  }

  vector<int> row_max(n), col_max(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      row_max[i] = max(row_max[i], a[i][j]);
      col_max[j] = max(col_max[j], a[i][j]);
    }
  }

  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int current = max(row_max[i]-1, col_max[j]-1);
      if (i > 0 && j > 0) {
        current = max(current, top_left[i-1][j-1]);
      }
      if (i > 0 && j+1 < m) {
        current = max(current, top_right[i-1][j+1]);
      }
      if (i +1 < n && j > 0) {
        current = max(current, bot_left[i+1][j-1]);
      }
      if (i +1 < n && j+1 < m) {
        current = max(current, bot_right[i+1][j+1]);
      }

      ans = min(ans, current);
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
