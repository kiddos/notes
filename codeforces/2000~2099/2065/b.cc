#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  bool found = false;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      found = true;
      break;
    }
  }

  if (found) {
    cout << "1" << endl;
  } else {
    cout << n << endl;
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
