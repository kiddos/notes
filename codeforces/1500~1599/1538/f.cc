#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 ops(i64 x) {
  i64 p = 1;
  i64 ans = 0;
  while (p <= x) {
    ans += x / p;
    p *= 10;
  }
  return ans;
}

void solve() {
  i64 l = 0, r = 0;
  cin >> l >> r;
  i64 L = ops(l);
  i64 R = ops(r);
  i64 ans = R - L;
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
