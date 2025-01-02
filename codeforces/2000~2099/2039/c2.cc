#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, m = 0;
  cin >> x >> m;
  i64 ans = (m - x) / x;
  if (x > m - x && x >= 1 && x <= m) {
    ans++;
  }
  for (i64 p = m-x + 1; p <= m + x; ++p) {
    i64 y = (x ^ p);
    if (y > m || y <= 0) continue;
    if (p % x == 0) {
      // cout << "y=" << y << endl;
      ans++;
    }
  }

  for (i64 y = 1; y <= min(x, m); ++y) {
    i64 p = y ^ x;
    if (p % y == 0) {
      // cout << "y=" << y << endl;
      ans++;
    }
  }
  if (x <= m) {
    ans--;
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
