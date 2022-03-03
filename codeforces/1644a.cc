#include <bits/stdc++.h>

using namespace std;

bool solve(string s) {
  bool r = false, g = false, b = false;
  for (char ch : s) {
    if (ch == 'r') r = true;
    else if (ch == 'g') g = true;
    else if (ch == 'b') b = true;
    else if (ch == 'R' && !r) return false;
    else if (ch == 'G' && !g) return false;
    else if (ch == 'B' && !b) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;
    bool ans = solve(s);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
