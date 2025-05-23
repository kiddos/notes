#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (s[i] == 'a') {
        s[i] = 'b';
      } else {
        s[i] = 'a';
      }
    } else {
      if (s[i] == 'z') {
        s[i] = 'y';
      } else {
        s[i] = 'z';
      }
    }
  }
  cout << s << endl;
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
