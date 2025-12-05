#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0, k = 0;
  cin >> x >> y >> k;

  auto find_position = [&](i64 val) -> i64 {
    i64 pos = val;
    for (int t = 0; t < x; ++t) {
      i64 remove = pos / y;
      pos -= remove;
    }
    return pos;
  };

  i64 l = 1, r = 1e12;
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 pos = find_position(mid);
    if (pos >= k) {
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
