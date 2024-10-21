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

  for (int i = n-2; i >= 1; --i) {
    for (int j = m-2; j >= 1; --j) {
      if (a[i][j] == 0) {
        int min_val = min(a[i+1][j], a[i][j+1]);
        a[i][j] = min_val - 1;
      }
    }
  }

  // check
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (a[i][j-1] >= a[i][j]) {
        cout << "-1" << endl;
        return;
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 1; i < n; ++i) {
      if (a[i-1][j] >= a[i][j]) {
        cout << "-1" << endl;
        return;
      }
    }
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += a[i][j];
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
