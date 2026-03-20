#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0, a = 0, b = 0;
  cin >> x >> y >> a >> b;
  i64 min_val = min(x, y);
  i64 diff = abs(x - y);
  i64 ans = min_val * min(b, a * 2) + diff * a;
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
