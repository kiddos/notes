#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int q = 0, a = 0;
  for (int i = 0; i < n; ++i) {
    q += s[i] == 'Q';
    a += s[i] == 'A';
    if (a > q) {
      a = q;
    }
  }
  if (a >= q) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
