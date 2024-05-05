#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  i64 ans = 0;
  int ones = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (ones > 0) {
        ans += ones + 1;
      }
    } else if (s[i] == '1') {
      ones++;
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
