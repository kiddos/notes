#include <bits/stdc++.h>

using namespace std;

bool solve(string s, char c) {
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] == c && i % 2 == 0) return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    string s;
    char c;
    cin >> s >> c;
    bool ans = solve(s, c);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
