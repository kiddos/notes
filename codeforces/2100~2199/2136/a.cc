#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;
  if (a >= b) {
    if (a > 2 * b + 2) {
      cout << "NO" << endl;
      return;
    }
  } else {
    if (b > 2 * a + 2) {
      cout << "NO" << endl;
      return;
    }
  }

  c -= a;
  d -= b;
  if (c >= d) {
    if (c > 2 * d + 2) {
      cout << "NO" << endl;
      return;
    }
  } else {
    if (d > 2 * c + 2) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
