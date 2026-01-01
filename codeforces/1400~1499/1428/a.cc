#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    i64 ans = abs(y1 - y2);
    cout << ans << endl;
  } else if (y1 == y2) {
    i64 ans = abs(x1 - x2);
    cout << ans << endl;
  } else {
    i64 ans = abs(x1 - x2) + abs(y1 - y2) + 2;
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
