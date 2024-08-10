#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;

  bool done = false;
  for (int i = 0, j = 0; i < (int)s.length(); ++i) {
    if (s[i] == '?') {
      s[i] = t[j++];
    } else if (s[i] == t[j]) {
      j++;
    }

    if (j == (int)t.length()) {
      done = true;
      while (i < (int)s.length()) {
        if (s[i] == '?') s[i] = 'a';
        i++;
      }
      break;
    }
  }

  if (done) {
    cout << "YES" << endl;
    cout << s << endl;
  } else {
    cout << "NO" << endl;
  }
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
