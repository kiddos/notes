#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 range(i64 a, i64 b, i64 c) {
  i64 max_val = max({a, b, c});
  i64 min_val = min({a, b, c});
  return max_val - min_val;
}

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  i64 ans = min({
    range(a, b, c),
    range(b+c, b, c),
    range(a, a+c, c),
    range(a, b, a+b),
  });
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
