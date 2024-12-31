#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int suf = 0, pre = 0;
  for (char c : s) {
    suf += c == 's';
    pre += c == 'p';
  }
  if (suf == 0 || pre == 0) {
    cout << "YES" << endl;
    return;
  }
  if (pre == 1 && s.back() == 'p') {
    cout << "YES" << endl;
    return;
  }
  if (suf == 1 && s[0] == 's') {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
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
