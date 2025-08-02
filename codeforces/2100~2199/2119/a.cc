#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, x = 0, y = 0;
  cin >> a >> b >> x >> y;
  if (a == b) {
    cout << "0" << endl;
    return;
  }
  if (a > b) {
    if ((a^1) == b) {
      cout << y << endl;
    } else {
      cout << "-1" << endl;
    }
    return;
  }
  i64 ans = 0;
  while (a < b) {
    if (a % 2 == 0) {
      a++;
      ans += min(x, y);
    } else {
      ans += x;
      a++;
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
