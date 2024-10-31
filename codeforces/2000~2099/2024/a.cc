#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;

  i64 l = 0, r = a;
  i64 x = a;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (a - mid >= b - 2 * mid) {
      x = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  int ans = a - x;
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
