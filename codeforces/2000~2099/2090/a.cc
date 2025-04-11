#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0, a = 0;
  cin >> x >> y >> a;
  x *= 2;
  y *= 2;
  a = a * 2 + 1;
  i64 sum = x + y;
  a %= sum;
  if (x > a) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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
