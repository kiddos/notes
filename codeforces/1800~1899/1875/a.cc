#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, n = 0;
  cin >> a >> b >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  i64 ans = b - 1;
  for (int i = 0; i < n; ++i) {
    ans += min(a, x[i]+1) - 1;
  }
  ans += 1;
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
