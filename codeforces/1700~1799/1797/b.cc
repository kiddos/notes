#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  }

  int require = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int c1 = a[i][j];
      int c2 = a[n-i-1][n-j-1];
      if (c1 != c2) {
        require++;
        a[i][j] = c2;
      }
    }
  }

  if (require > k) {
    cout << "NO" << endl;
    return;
  }

  if (n == 1) {
    cout << "YES" << endl;
    return;
  }

  if (n % 2 == 1) {
    cout << "YES" << endl;
    return;
  }

  int left = k - require;
  if (left % 2 == 0) {
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
