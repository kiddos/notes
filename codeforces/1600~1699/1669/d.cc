#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int i = 0;
  while (i < n) {
    if (s[i] == 'W') {
      i++;
    } else {
      int r = 0, b = 0;
      while (i < n && s[i] != 'W') {
        r += s[i] == 'R';
        b += s[i] == 'B';
        i++;
      }

      if (r == 0 || b == 0) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
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
