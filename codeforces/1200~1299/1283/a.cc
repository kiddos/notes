#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, m = 0;
  cin >> h >> m;
  int total = h * 60 + m;
  int ans = 1440 - total;
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
