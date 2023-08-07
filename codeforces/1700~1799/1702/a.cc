#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m = 0;
  cin >> m;
  int r = 1;
  while (r * 10 <= m) {
    r *= 10;
  }

  int ans = m - r;
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
