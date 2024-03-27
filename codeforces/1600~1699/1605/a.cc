#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a1 = 0, a2 = 0, a3 = 0;
  cin >> a1 >> a2 >> a3;
  // a1 + a3 + d = a2 * 2 - d * 2
  // 3 * d = a2 * 2 - a1 - a3
  i64 dx = (a2 * 2 - a1 - a3) / 3;
  i64 d = min({
    abs(a1 + a3 + dx * 3 - a2 * 2),
    abs(a1 + a3 + (dx+1) * 3 - a2 * 2),
    abs(a1 + a3 + (dx-1) * 3 - a2 * 2),
  });
  cout << d << endl;
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
