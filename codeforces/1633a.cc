#include <bits/stdc++.h>

using namespace std;

int solve(int n)  {
  if (n % 7 == 0) return n;

  string s = to_string(n);
  for (int i = 0; i < s.length(); ++i) {
    char cc = s[i];
    for (int d = 0; d <= 9; ++d) if (d + '0' != cc) {
      if (i == 0 && d == 0) continue;
      s[i] = d + '0';
      int val = stoi(s);
      if (val % 7 == 0) {
        return val;
      }
    }
    s[i] = cc;
  }
  return n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0, n = 0;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
