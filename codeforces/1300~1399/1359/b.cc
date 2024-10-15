#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, x = 0, y = 0;
  cin >> n >> m >> x >> y;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (x * 2 > y) {
    int ans = 0;
    for (int r = 0; r < n; ++r) {
      int i = 0;
      while (i < m) {
        if (a[r][i] == '*') {
          i++;
        } else {
          int j = i;
          while (j+1 < m && a[r][j+1] == '.') {
            j++;
          }
          int len = j - i + 1;
          ans += len / 2 * y;
          ans += (len % 2) * x;
          i = j+1;
        }
      }
    }

    cout << ans << endl;
  } else {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == '.') {
          ans += x;
        }
      }
    }
    cout << ans << endl;
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
