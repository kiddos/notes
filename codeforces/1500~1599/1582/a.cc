#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  i64 total = a + b * 2 + c * 3;
  i64 half = total / 2;

  i64 h = half;
  i64 c3 = min(h / 3, c);
  h -= c3 * 3;
  i64 c2 = min(h / 2, b);
  h -= c2 * 2;
  i64 c1 = min(h, a);
  h -= c1;
  i64 x = (half - h);
  i64 y = total - x;
  // cout << "x=" << x << ", y=" << y << endl;
  i64 diff = y - x;
  cout << diff << endl;
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
