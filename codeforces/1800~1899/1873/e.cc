#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<i64> h(n+2);
  for (int i = 1; i <= n; ++i) cin >> h[i];

  int m = n+2;
  auto can_fill = [&](i64 y) -> bool {
    h[0] = h.back() = y;
    vector<i64> left = h;
    for (int i = 1; i < m; ++i) {
      left[i] = max(left[i], left[i-1]);
    }
    vector<i64> right = h;
    for (int i = m-2; i >= 0; --i) {
      right[i] = max(right[i], right[i+1]);
    }
    i64 w = 0;
    for (int i = 1; i < m-1; ++i) {
      w += max(min({left[i], right[i], y}) - h[i], 0LL);
    }
    // cout << y << " = " << w << endl;
    return w <= x;
  };

  i64 l = 1, r = numeric_limits<int>::max();
  i64 ans = 1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (can_fill(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
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
