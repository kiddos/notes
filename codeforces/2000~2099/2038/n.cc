#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  if (s[0] < s[2]) {
    s[1] = '<';
  } else if (s[0] == s[2]) {
    s[1] = '=';
  } else if (s[0] > s[2]) {
    s[1] = '>';
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
