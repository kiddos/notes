#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;

  auto longest = [&](i64 x, i64 y) -> int {
    string s1 = to_string(x), s2 = to_string(y);
    int len = 0;
    for (int i = 0; i < (int)s1.length(); ++i) {
      if (s1[i] == s2[len]) {
        len++;
      }
      if (len >= (int)s2.length()) {
        break;
      }
    }
    return s1.length() + s2.length() - len * 2;
  };

  i64 y = 1;
  int ans = 1000;
  while (y <= 1e18) {
    ans = min(ans, longest(n, y));
    y <<= 1;
  }
  cout << ans << endl;
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
