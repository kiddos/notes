#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0, k = 0;
  cin >> x >> y >> k;
  i64 x_move = (x + k - 1) / k;
  i64 y_move = (y + k - 1) / k;
  if (x_move > y_move) {
    i64 ans = (x_move-1) * 2 + 1;
    cout << ans << endl;
  } else {
    i64 ans = y_move * 2;
    cout << ans << endl;
  }
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
