#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<i64>> a(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<vector<int>> p(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + (grid[i-1][j-1] == '1' ? 1 : 0);
    }
  }

  vector<int> diffs;
  for (int i = k; i <= n; ++i) {
    for (int j = k; j <= m; ++j) {
      int without_cap = p[i][j] - p[i-k][j] - p[i][j-k] + p[i-k][j-k];
      int with_cap = k * k - without_cap;
      int min_both = min(without_cap, with_cap);
      int diff = k * k - min_both * 2;
      diffs.push_back(diff);
    }
  }

  i64 without_cap_total = 0, with_cap_total = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '1') {
        without_cap_total += a[i][j];
      } else {
        with_cap_total += a[i][j];
      }
    }
  }

  int g = 0;
  for (int d : diffs) {
    // cout << "d=" << d << endl;
    g = gcd(g, d);
  }

  i64 total_diff = abs(without_cap_total - with_cap_total);
  // dont need to change diff
  if (total_diff == 0) {
    cout << "YES" << endl;
    return;
  }

  // cannot change diff
  if (g == 0) {
    cout << "NO" << endl;
    return;
  }

  if (total_diff % g == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
