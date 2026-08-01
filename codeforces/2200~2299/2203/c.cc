#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 s = 0, m = 0;
  cin >> s >> m;

  auto possible = [&](i64 count) -> bool {
    i64 left = s;
    for (int b = 62; b >= 0; --b) {
      i64 p2 = 1LL << b;
      if (m & p2) {
        i64 take = min(left / p2, count);
        left -= take * p2;
      }
    }
    return left == 0;
  };

  i64 l = 1, r = 2e18;
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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
