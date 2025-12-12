#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int one = 0, zero = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      if (s[i] == '1') {
        one++;
      } else if (s[i] == '0') {
        zero++;
      }
    }
  }
  int ans = max(one, zero);
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
