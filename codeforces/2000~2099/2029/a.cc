#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 l = 0, r = 0, k = 0;
  cin >> l >> r >> k;

  i64 L = l, R = r;
  i64 ans = l-1;
  while (L <= R) {
    i64 mid = L + (R-L) / 2;
    if (mid * k <= r) {
      ans = mid;
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  cout << ans - l + 1 << endl;
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
