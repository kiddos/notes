#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  if (y > 0) {
    x -= 2 * y;
    if (x < 0) {
      cout << "NO" << endl;
      return;
    }
  } else if (y < 0) {
    x -= 4 * abs(y);
    if (x < 0) {
      cout << "NO" << endl;
      return;
    }
  }

  if (x % 3 == 0) {
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
