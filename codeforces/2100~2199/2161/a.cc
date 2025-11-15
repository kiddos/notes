#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int R0 = 0, X = 0, D = 0, n = 0;
  cin >> R0 >> X >> D >> n;
  string s;
  cin >> s;

  int R = R0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ans++;
      R -= D;
      R = max(R, 0);
    } else if (s[i] == '2') {
      if (R < X) {
        ans++;
      }
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
