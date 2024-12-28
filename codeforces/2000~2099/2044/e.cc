#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 k0 = 0, l1 = 0, r1 = 0, l2 = 0, r2 = 0;
  cin >> k0 >> l1 >> r1 >> l2 >> r2;

  i64 ans = 0;
  for (i64 k = 1; k <= r2; k *= k0) {
    i64 l = l1, r = r1;
    i64 low = -1;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      i64 y = mid * k;
      if (y >= l2) {
        r = mid-1;
        low = mid;
      } else {
        l = mid+1;
      }
    }

    l = l1;
    r = r1;
    i64 high = -1;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      i64 y = mid * k;
      if (y <= r2) {
        l = mid+1;
        high = mid;
      } else {
        r = mid-1;
      }
    }
    // cout <<"k=" << k << ",low=" << low << ", high=" << high << endl;
    if (low >= 0 && high >= 0) {
      ans += high - low + 1;
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
