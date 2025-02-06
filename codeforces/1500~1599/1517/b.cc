#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }
  vector<array<int,3>> paths;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      paths.push_back({b[i][j], i, j});
    }
  }
  sort(paths.begin(), paths.end());
  vector<vector<int>> a(n, vector<int>(m));
  int col = 0, k = 0;
  for (; col < m; ++col, ++k) {
    auto [l, r, c] = paths[k];
    a[r][col] = l;
  }
  vector<vector<int>> rows(n);
  for (;k < (int)paths.size(); ++k) {
    auto [l, r, c] = paths[k];
    rows[r].push_back(l);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!a[i][j]) {
        a[i][j] = rows[i].back();
        rows[i].pop_back();
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
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
