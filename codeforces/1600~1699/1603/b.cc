#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// let z = n % x = y % n
// n = x * k1 + z
// y = k2 * n + z
// n - y = x * k1 - k2 * n
// => (1 + k2) * n = x * k1 + y

void solve() {
  i64 x = 0, y = 0;
  cin >> x >> y;

  if (x > y) {
    cout << x + y << endl;
  } else {
    i64 p = y % x;
    cout << y - p / 2 << endl;
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
