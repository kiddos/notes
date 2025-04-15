#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> x(k);
  iota(x.begin(), x.end(), 1);

  if (k <= n && n % k == 0) {
    int offset = 0;
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        a[i][j] = x[(j * n + i + offset) % k];
      }
      offset++;
    }
  } else if (k <= m && m % k == 0) {
    int offset = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = x[(i * m + j + offset) % k];
      }
      offset++;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = x[(i * m + j) % k];
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
