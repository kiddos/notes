#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  int same = min(x, y);
  int rest = max(x, y) - same;
  int ans = same * 2;
  if (rest > 0) {
    if (rest == 1) {
      ans++;
    } else {
      ans++;
      rest--;
      ans += rest * 2;
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
