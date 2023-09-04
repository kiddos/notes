#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0, x = 0, y = 0;
  cin >> a >> b >> c >> x >> y;

  auto reduce = [&](i64& x, i64& a) {
    i64 b = min(x, a);
    x -= b;
    a -= b;
  };

  reduce(x, a);
  reduce(x, c);
  reduce(y, b);
  reduce(y, c);
  if (x > 0 || y > 0) {
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
