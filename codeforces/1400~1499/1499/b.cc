#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  bool can_be_zero = true;
  for (int i = 0; i+1 < n; ++i) {
    if (s[i] == s[i+1]) {
      if (s[i] == '1') {
        can_be_zero = false;
      } else if (s[i] == '0') {
        if (!can_be_zero) {
          cout << "NO" << endl;
          return;
        }
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
