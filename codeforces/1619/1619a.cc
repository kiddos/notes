#include <bits/stdc++.h>

using namespace std;

bool solve(string s) {
  if (s.length() % 2 == 1) return false;
  int n = s.length();
  for (int i = 0, j = n/2; i < n/2 && j < n; ++i, ++j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    bool ans = solve(s);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
