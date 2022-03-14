#include <bits/stdc++.h>

using namespace std;

bool solve(string s) {
  int n = 0;
  for (char ch : s) n += ch == 'N';
  if (n == 1) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    string s;
    cin >> s;
    bool ans = solve(s);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
