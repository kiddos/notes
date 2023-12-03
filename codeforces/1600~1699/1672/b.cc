#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  if (s.back() != 'B') {
    cout << "NO" << endl;
    return;
  }

  int n = s.length();
  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    a += s[i] == 'A';
    b += s[i] == 'B';
    if (b > a) {
      cout << "NO" << endl;
      return;
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
