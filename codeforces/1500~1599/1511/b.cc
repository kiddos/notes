#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  int g = 1;
  for (int k = 1; k < c; ++k) {
    g *= 10;
  }
  i64 x = g, y = g;
  for (int k = c; k < a; ++k) {
    x *= 10;
  }
  for (int k = c; k < b; ++k) {
    y *= 10;
  }
  x += g;
  y += 2 * g;
  while (gcd(x, y) > g) {
    y += g;
  }

  cout << x << " " << y << endl;
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
