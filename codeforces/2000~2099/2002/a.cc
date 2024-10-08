#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  i64 w = min(n, k);
  i64 h = min(m, k);
  i64 ans = w * h;
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
