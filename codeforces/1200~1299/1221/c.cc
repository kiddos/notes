#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 c = 0, m = 0, x = 0;
  cin >> c >> m >> x;

  i64 possible_teams = min(c, m);
  i64 l = 0, r = possible_teams;
  i64 ans = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 extra = (c - mid) + (m - mid) + x;
    bool enough = extra >= mid;
    if (enough) {
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
