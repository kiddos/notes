#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 p = 0;
  vector<i64> t(3);
  cin >> p;
  for (int i = 0; i < 3; ++i) {
    cin >> t[i];
  }
  i64 ans = numeric_limits<i64>::max();
  for (int i = 0; i < 3; ++i) {
    i64 require = ((p + t[i] - 1) / t[i]) * t[i];
    ans = min(ans, require - p);
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
