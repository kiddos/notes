#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  i64 l = 1, r = 1000000000000000000LL;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 div = mid / n;
    i64 not_div = mid - div;
    if (not_div >= k) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
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
