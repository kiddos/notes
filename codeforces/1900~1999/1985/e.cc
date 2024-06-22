#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0, z = 0;
  i64 k = 0;
  cin >> x >> y >> z >> k;
  i64 ans = 0;
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= y; ++j) {
      i64 area = i * j;
      if (area > k) break;
      if (k % area != 0) continue;
      i64 h = k / area;
      if (h > z) continue;

      i64 choice = (i64)(x - i + 1) * (y - j + 1) * (z - h + 1);
      ans = max(ans, choice);
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
