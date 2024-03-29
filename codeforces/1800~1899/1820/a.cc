#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (s == "_") {
    cout << "2" << endl;
    return;
  }
  if (s == "^") {
    cout << "1" << endl;
    return;
  }

  int ans = 0;
  if (s[0] == '_') {
    ans++;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '_' && (i == n-1 || s[i+1] != '^')) {
      ans++;
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
