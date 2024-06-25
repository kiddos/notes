#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int zeros = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      zeros++;
    } else {
      if (zeros) {
        ans++;
        zeros = 0;
      }
    }
  }
  if (zeros) ans++;
  ans = min(ans, 2);
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
