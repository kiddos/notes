#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// UU -> Bob
// UD -> Alice
// DU -> Alice
// DD -> Bob
// U  -> Alice
//
// UUU -> Alice
// UUD -> Bob
// UDU -> Bob

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int up = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') {
      up++;
    }
  }
  if (up % 2 == 1) {
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
