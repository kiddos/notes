#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int zero = 0;
  for (int i = 0, b = 0; i < n; ++i) {
    if (s[i] == '(') {
      b++;
    } else if (s[i] == ')') {
      b--;
    }
    if (b == 0) {
      zero++;
    }
  }
  if (zero > 1) {
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
