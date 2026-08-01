#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> s(2);
  cin >> s[0] >> s[1];
  int n = s[0].length();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[0][i] == '0' && s[1][i] == '0') {
      if (i > 0) {
        if (s[0][i-1] == '0') {
          s[0][i-1] = s[0][i] = s[1][i] = 'X';
          ans++;
        } else if (s[1][i-1] == '0') {
          s[1][i-1] = s[0][i] = s[1][i] = 'X';
          ans++;
        }
      }
      if (s[0][i] == '0' && s[1][i] == '0' && i+1 < n) {
        if (s[0][i+1] == '0') {
          s[0][i+1] = s[0][i] = s[1][i] = 'X';
          ans++;
        } else if (s[1][i+1] == '0') {
          s[1][i+1] = s[0][i] = s[1][i] = 'X';
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
