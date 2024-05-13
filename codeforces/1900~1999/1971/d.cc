#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      j++;
    }
    i = j;
    ans++;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i-1] == '0' && s[i] == '1') {
      ans--;
      break;
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
