#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, x = 0, y = 0, n = 0;
  cin >> a >> b >> x >> y >> n;

  auto compute_product = [&](i64 a1, i64 a2, i64 x1, i64 x2, i64 n1) -> i64 {
    i64 p1 = max(a1-n1, x1);
    n1 -= a1-p1;
    i64 p2 = max(a2-n1, x2);
    return p1 * p2;
  };

  i64 ans = min(compute_product(a, b, x, y, n), compute_product(b, a, y, x, n));
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
