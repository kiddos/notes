#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int solve(int k, int a, int b, int x, int y) {
  int cook_a = k >= a ? (k - a + x) / x : 0;
  k -= cook_a * x;
  int cook_b = k >= b ? (k - b + y) / y : 0;
  k -= cook_b * y;
  return cook_a + cook_b;
}

void solve() {
  int k = 0, a = 0, b = 0, x = 0, y = 0;
  cin >> k >> a >> b >> x >> y;
  int ans = max(solve(k, a, b, x, y), solve(k, b, a, y, x));
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
