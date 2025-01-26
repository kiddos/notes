#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 l = 0, r = 0, G = 0;
  cin >> l >> r >> G;
  i64 l0 = (l+G-1) / G * G;
  i64 r0 = r / G * G;
  pair<i64,i64> ans = {-1, -1};
  // I didn't expect this to work
  // WTF
  for (i64 k1 = 0; k1 <= 25; ++k1) {
    for (i64 k2 = 0; k2 <= 25; ++k2) {
      i64 L = l0 + k1 * G;
      i64 R = r0 - k2 * G;
      if (L > R) break;

      if (gcd(L, R) == G) {
        if (ans.first < 0 || R-L > ans.second - ans.first) {
          ans = {L, R};
        }
      }
    }
  }
  cout << ans.first << " " << ans.second << endl;
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
