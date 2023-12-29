#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;

  auto find_bound = [&](int n) -> array<int, 6> {
    int x = 0, y = 0;
    int max_x = 0, min_x = 0;
    int max_y = 0, min_y = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') {
        x--;
      } else if (s[i] == 'R') {
        x++;
      } else if (s[i] == 'U') {
        y--;
      } else if (s[i] == 'D') {
        y++;
      }
      max_x = max(max_x, x);
      max_y = max(max_y, y);
      min_x = min(min_x, x);
      min_y = min(min_y, y);
    }
    return {x, y, min_x, min_y, max_x, max_y};
  };

  auto get_start = [&](array<int, 6> bound) -> array<int, 2> {
    auto [x, y, min_x, min_y, max_x, max_y] = bound;
    int sx = 1, sy = 1;
    if (x >= 0) {
      sx = -min_x+1;
    } else {
      sx = m - max_x;
    }

    if (y >= 0) {
      sy = -min_y+1;
    } else {
      sy = n - max_y;
    }
    // cout << "(" << min_x << "," << min_y << ") (" << max_x << "," << max_y << ")" << endl;
    return {sx, sy};
  };

  array<int, 2> ans = {1, 1};
  int l = 1, r = s.length();
  while (l <= r) {
    int mid = l + (r-l) / 2;
    auto bound = find_bound(mid);
    int w = bound[4] - bound[2] + 1;
    int h = bound[5] - bound[3] + 1;
    // cout << "len=" << mid << ", w=" << w << ",h=" << h << endl;
    if (w <= m && h <= n) {
      l = mid+1;
      ans = get_start(bound);
    } else {
      r = mid-1;
    }
  }

  cout << ans[1] << " " << ans[0] << endl;
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
