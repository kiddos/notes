#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int y = 0, x = 0;
    cin >> y >> x;
    int level = max(y, x);
    i64 base = (level-1) * 2 - 1;
    i64 height = level-1;
    i64 total_prefix = (base + 1) * height / 2;
    i64 ans = 0;
    if (level % 2 == 0) {
      // start from row decreasing
      if (x == level) {
        ans = total_prefix + y;
      } else {
        ans = total_prefix + level + level - x;
      }
    } else {
      // start from col increasing
      if (y == level) {
        ans = total_prefix + x;
      } else {
        ans = total_prefix + level + level - y;
      }
    }
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
