#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  // y = -x + b
  // => b = y + x
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 x = 0, y = 0;
    cin >> x >> y;
    i64 b = x + y;
    ans = max(ans, b);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
