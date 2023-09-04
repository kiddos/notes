#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  if (s == "()") {
    cout << "NO" << endl;
    return;
  }

  int n = s.length();
  bool found = false;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      found = true;
      break;
    }
  }

  string ans;
  if (found) {
    for (int i = 0; i < n; ++i) {
      ans += "()";
    }
  } else {
    ans = string(n, '(') + string(n, ')');
  }
  cout << "YES" << endl;
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
