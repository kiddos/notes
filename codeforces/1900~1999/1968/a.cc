#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;
  int z = 0;
  int ans = 1;
  for (int y = x-1; y >= 1; --y) {
    if (gcd(y, x) + y > z) {
      z = gcd(y, x) + y;
      ans = y;
    }
  }
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
