#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, a = 0, b = 0;
  cin >> n >> m >> a >> b;

  if (a * n != b * m) {
    cout << "NO" << endl;
    return;
  }

  int d0 = 1;
  for (; d0 < m; ++d0) {
    if ((d0 * n) % m == 0) {
      break;
    }
  }

  vector<vector<int>> ans(n, vector<int>(m));
  int d = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < a; ++j) {
      ans[i][(j+d)%m] = 1;
    }
    d += d0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j];
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
