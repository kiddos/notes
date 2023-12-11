#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string p = s;
  for (char c = '1'; c <= '8'; ++c) {
    p[1] = c;
    if (p != s) {
      cout << p << endl;
    }
  }
  p = s;
  for (char c = 'a'; c <= 'h'; ++c) {
    p[0] = c;
    if (p != s) {
      cout << p << endl;
    }
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
