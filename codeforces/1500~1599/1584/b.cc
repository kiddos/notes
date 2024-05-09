#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;
  if (n == 1) {
    cout << (m + 2) / 3 << endl;
  } else if (m == 1) {
    cout << (n + 2) / 3 << endl;
  } else {
    auto get_answer = [](int x, int y) -> i64 {
      i64 row = y / 3;
      i64 rest = (x + 2) / 3 * (y % 3);
      return row * x + rest;
    };
    i64 ans = min(get_answer(n, m), get_answer(m, n));
    cout << ans << endl;
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
