#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int x = 0;
  cin >> x;
  int n = s.length();
  string w(n, '1');
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (i+x < n) {
        w[i+x] = '0';
      }
      if (i-x >= 0) {
        w[i-x] = '0';
      }
    }
  }

  string s2(n, '0');
  for (int i = 0; i < n; ++i) {
    if (i+x < n && w[i+x] == '1') {
      s2[i] = '1';
    }
    if (i-x >= 0 && w[i-x] == '1') {
      s2[i] = '1';
    }
  }
  if (s == s2) {
    cout << w << endl;
  } else {
    cout << "-1" << endl;
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
