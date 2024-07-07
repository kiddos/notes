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

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<int>> ids(n, vector<int>(m));
  function<void(int,int,int)> dfs = [&](int r, int c, int id) {
    if (r < 0 || r >= n || c < 0 || c >= m) {
      return;
    }
    if (ids[r][c]) {
      return;
    }
    if (grid[r][c] != '#') {
      return;
    }
    ids[r][c] = id;
    for (vector<int>& d : delta) {
      dfs(r + d[0], c + d[1], id);
    }
  };

  int id = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        if (!ids[i][j]) {
          dfs(i, j, id++);
        }
      }
    }
  }

  vector<int> sizes(id), min_r(id, n), max_r(id), min_c(id, m), max_c(id);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ids[i][j]) {
        min_r[ids[i][j]] = min(min_r[ids[i][j]], max(i-1, 0));
        max_r[ids[i][j]] = max(max_r[ids[i][j]], min(i+1, n-1));
        min_c[ids[i][j]] = min(min_c[ids[i][j]], max(j-1, 0));
        max_c[ids[i][j]] = max(max_c[ids[i][j]], min(j+1, m-1));
        sizes[ids[i][j]]++;
      }
    }
  }

  vector<int> pr(n+1), pc(m+1);
  vector<vector<int>> p2(n+1, vector<int>(m+1));
  for (int i = 1; i < id; ++i) {
    pr[min_r[i]] += sizes[i];
    pr[max_r[i]+1] -= sizes[i];

    pc[min_c[i]] += sizes[i];
    pc[max_c[i]+1] -= sizes[i];

    p2[min_r[i]][min_c[i]] += sizes[i];
    p2[max_r[i]+1][min_c[i]] -= sizes[i];
    p2[min_r[i]][max_c[i]+1] -= sizes[i];
    p2[max_r[i]+1][max_c[i]+1] += sizes[i];
  }

  for (int i = 1; i <= n; ++i) {
    pr[i] += pr[i-1];
    p2[i][0] += p2[i-1][0];
  }
  for (int j = 1; j <= m; ++j) {
    pc[j] += pc[j-1];
    p2[0][j] += p2[0][j-1];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      p2[i][j] += p2[i-1][j] + p2[i][j-1] - p2[i-1][j-1];
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << pr[i] << " ";
  // }
  // cout << endl;
  // for (int j = 0; j <= m; ++j) {
  //   cout << pc[j] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     cout << p2[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> row_empty(n), col_empty(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') {
        row_empty[i]++;
        col_empty[j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int sum = pr[i] + pc[j] - p2[i][j];
      // cout << "i=" << i << ", j=" << j << ", sum=" << sum << endl;
      sum += row_empty[i];
      sum += col_empty[j];
      if (grid[i][j] == '.') {
        sum--;
      }

      ans = max(ans, sum);
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
