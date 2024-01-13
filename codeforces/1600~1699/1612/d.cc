#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, x = 0;
  cin >> a >> b >> x;

  function<bool(i64,i64)> compute = [&](i64 a, i64 b) {
    if (a == x || b == x) {
      return true;
    }
    if (a < b) {
      return compute(b, a);
    }
    if (x > max(a, b)) {
      return false;
    }
    if (a == 0 || b == 0) {
      return false;
    }
    i64 count = max(1LL, (a - max(x, b)) / (2 * b));
    return compute(a - b * count, b);
  };

  bool ans = compute(a, b);
  if (ans) {
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
