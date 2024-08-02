#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c != s[i]) {
          s.insert(i, 1, c);
          cout << s << endl;
          return;
        }
      }
    }
  }

  if (n == 1) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (c != s.back()) {
        s.push_back(c);
        cout << s << endl;
        return;
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (c != s[i] && c != s[i-1]) {
        s.insert(i, 1, c);
        cout << s << endl;
        return;
      }
    }
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
