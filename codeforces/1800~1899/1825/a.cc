#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  int ans = -1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i-1]) {
      int left = i-1;
      int right = n-i-2;
      int len = left + right + 2;
      ans = max(ans, len);
    }
  }
  for (int i = 2; i < n; ++i) {
    if (s[i] != s[i-2]) {
      int left = i-2;
      int right = n-i-2;
      int len = left + right + 3;
      ans = max(ans, len);
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
