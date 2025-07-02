#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// (3, 2)
// (4, 3), (8, 3)
// (5, 4), (10, 4), (15, 4)
// (6, 5), (12, 5), (18, 5), (24, 5)
// (7, 6), (14, 6), (21, 6), (28, 6), (35, 6)

void solve() {
  i64 x = 0, y = 0;
  cin >> x >> y;
  i64 ans = 0;
  for (i64 mod = 1, a = 3, b = 2; mod * a <= x && b <= y; ++mod, ++a, ++b) {
    i64 p = mod * a;
    i64 first = (x - p + mod) / mod;
    i64 second = (y - b + 1);
    i64 pairs = min(first, second);
    ans += pairs;
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
