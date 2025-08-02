#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  int len1 = s.length(), len2 = t.length();
  int len = lcm(len1, len2);
  string s2;
  for (int l = 0; l < len; l += len1) {
    s2 += s;
  }
  for (int i = 0; i < len; i += len2) {
    if (s2.substr(i, len2) != t) {
      cout << "-1" << endl;
      return;
    }
  }
  cout << s2 << endl;
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
