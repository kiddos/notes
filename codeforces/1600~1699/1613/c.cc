#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 h = 0;
  cin >> n >> h;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  auto can_slay_dragon = [&](i64 k) -> bool {
    i64 total = 0;
    for (int i = 1; i < n; ++i) {
      i64 diff = a[i+1] - a[i];
      if (diff >= k) {
        total += k;
      } else {
        total += diff;
      }
    }
    total += k;
    return total >= h;
  };

  i64 l = 1, r = numeric_limits<i64>::max();
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (can_slay_dragon(mid)) {
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
