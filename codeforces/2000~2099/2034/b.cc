#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  int i = 0;
  int ans = 0;
  while (i < n) {
    if (s[i] == '1') {
      i++;
    } else {
      int j = 1;
      while (i < n && s[i] == '0' && j < m) {
        i++;
        j++;
      }
      if (i < n && s[i] == '0') {
        for (int j = 0; j < k && i < n; ++j, ++i) {
          s[i] = '1';
        }
        ans++;
      }
    }
  }
  // cout << s << endl;
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
