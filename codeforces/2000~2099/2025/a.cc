#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  int i = 0;
  while (i < (int)s.length() && i < (int)t.length() && s[i] == t[i]) {
    i++;
  }

  int ans = (i >= 1 ? (i+1) : 0) + (s.length() - i) + (t.length() - i);
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
