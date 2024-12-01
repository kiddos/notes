#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 w = 0, b = 0;
  cin >> w >> b;
  i64 l = 0, r = 500000;
  i64 ans = 0;

  auto possible = [&](i64 side) -> bool {
    i64 white = w, black = b;
    for (i64 count = side; count >= 1; --count) {
      if (white >= count) {
        white -= count;
      } else if (black >= count) {
        black -= count;
      } else {
        return false;
      }
    }
    return true;
  };
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
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
