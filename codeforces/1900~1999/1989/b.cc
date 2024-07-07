#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  int ans = n + m;
  for (int start = 0; start < m; ++start) {
    string s2 = t.substr(start);
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (j < m && s[i] == s2[j]) {
        j++;
      }
    }
    int rest = start + s2.length() - j;
    ans = min(ans, rest + n);
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
