#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, x = 0, t = 0;
  cin >> n >> x >> t;
  i64 unsatisfy = t / x;
  i64 first = max(n - unsatisfy, 0LL);
  i64 ans = first * unsatisfy;
  ans += min(n-1, unsatisfy-1) * min(n, unsatisfy) / 2;
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
