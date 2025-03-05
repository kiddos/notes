#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool has_7(i64 x) {
  while (x > 0) {
    i64 d = x % 10;
    if (d == 7) {
      return true;
    }
    x /= 10;
  }
  return false;
}

int min_ops(i64 x, i64 nine) {
  int ans = 0;
  while (!has_7(x)) {
    x += nine;
    ans++;
  }
  return ans;
}

void solve() {
  i64 n = 0;
  cin >> n;
  string s = to_string(n);
  int len = s.length();
  i64 p = 1;
  i64 nine = 0;
  int ans = 10;
  for (int i = 0; i < len; ++i, p *= 10) {
    nine += 9 * p;
    int ops = min_ops(n, nine);
    ans = min(ans, ops);
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
