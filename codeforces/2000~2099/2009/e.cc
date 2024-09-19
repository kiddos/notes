#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  i64 total = (k + n - 1 + k) * n / 2;

  auto compute_x = [&](int i) {
    i64 prefix = (k + i - 1 + k) * i / 2;
    i64 suffix = total - prefix;
    return abs(prefix - suffix);
  };

  i64 l = 0, r = n;
  i64 i = n;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 prefix = (k + mid - 1 + k) * mid / 2;
    i64 suffix = total - prefix;
    if (prefix >= suffix) {
      i = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  i64 ans = min(compute_x(i), compute_x(i-1));
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
