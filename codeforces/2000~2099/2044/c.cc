#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 m = 0, a = 0, b = 0, c = 0;
  cin >> m >> a >> b >> c;
  vector<i64> rows(2, m);
  i64 first = min(rows[0], a);
  rows[0] -= first;
  i64 second = min(rows[1], b);
  rows[1] -= second;
  i64 no_pref = min(rows[0] + rows[1], c);
  i64 ans = first + second + no_pref;
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
