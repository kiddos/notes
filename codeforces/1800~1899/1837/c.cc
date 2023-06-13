#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  string a = s;
  char last = '1';
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '?') {
      a[i] = last;
    } else {
      last = s[i];
    }
  }

  cout << a << endl;
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
