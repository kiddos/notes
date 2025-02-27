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

  map<int,int> ops;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ops[a[i][j]] = 1;
    }
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool found = false;
      for (vector<int>& d : delta) {
        int r2 = i+d[0], c2 = j+d[1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) {
          continue;
        }
        if (a[r2][c2] == a[i][j]) {
          found = true;
          break;
        }
      }
      if (found) {
        ops[a[i][j]] = max(ops[a[i][j]], 2);
      }
    }
  }

  int total = 0;
  for (auto [val, count] : ops) {
    total += count;
  }

  int ans = total;
  for (auto [val, count] : ops) {
    ans = min(ans, total - count);
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
