#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, m = 0;
  cin >> x >> m;

  int ans = 0;
  for (int y = 1; y <= min(x * 2, m); ++y) {
    if (x == y) continue;

    i64 z = y ^ x;
    if (x % z == 0 || y % z == 0) {
      ans++;
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
