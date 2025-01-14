#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  int x = 0, y = 0, z = 0;
  for (int b = 30; b >= 0; --b) {
    int mask = 1<<b;
    int m1 = l & mask, m2 = r & mask;
    if (m1 != m2) {
      x |= mask;
      y = x-1;
      break;
    } else {
      if (m1) {
        x |= mask;
      }
    }
  }

  for (int i = l; i <= r; ++i) {
    if (i != x && i != y) {
      z = i;
      break;
    }
  }

  cout << x << " " << y << " " << z << endl;
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
