#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 find_max_y(i64 x, i64 R) {
  i64 y = 0;
  i64 l = 0, r = R;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (mid * mid + x * x <= R * R) {
      y = mid;
      l = mid + 1;
    } else {
      r = mid-1;
    }
  }
  return y;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  map<int,i64> max_y;
  for (int i = 0; i < n; ++i) {
    for (int px = x[i] - r[i]; px <= x[i] + r[i]; ++px) {
      max_y[px] = max(max_y[px], find_max_y(abs(px - x[i]), r[i]));
    }
  }

  i64 ans = 0;
  for (auto& [x, y] : max_y) {
    ans += y * 2 + 1;
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
