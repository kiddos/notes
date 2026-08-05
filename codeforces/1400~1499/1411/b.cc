#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_fair(i64 x) {
  string s = to_string(x);
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    if (s[i] != '0') {
      int c = s[i] -'0';
      if (x % c != 0) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  i64 n = 0;
  cin >> n;
  i64 l = 1;
  for (int i = 1; i <= 9; ++i) {
    l = lcm(i, l);
  }
  for (int offset = 0; offset <= l; ++offset) {
    i64 x = n + offset;
    if (is_fair(x)) {
      cout << x << endl;
      return;
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
