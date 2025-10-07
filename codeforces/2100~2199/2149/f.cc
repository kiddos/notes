#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, d = 0;
  cin >> h >> d;

  auto health_require = [&](i64 len) -> i64 {
    return (len + 1) * len / 2;
  };

  auto has_enough_health = [&](i64 rest) -> bool {
    i64 segment = rest+1;
    i64 consecutive_length = d / segment;
    i64 extra = d - consecutive_length * segment;
    i64 require = health_require(consecutive_length) * (segment - extra) +
      health_require(consecutive_length+1) * extra - rest;
    return h > require;
  };

  i64 l = 0, r = d;
  i64 rest = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (has_enough_health(mid)) {
      rest = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  i64 ans = rest + d;
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
