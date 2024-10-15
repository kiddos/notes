#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  int n = s.length();
  vector<bool> found(26);
  for (int i = 0; i < n; ++i) {
    found[s[i] - 'a'] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (found[t[i] - 'a']) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
