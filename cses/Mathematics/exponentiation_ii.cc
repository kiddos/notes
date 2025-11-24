#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;
i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }
    n >>= 1;
    x = (x * x);
    x %= mod;
  }
  return ans;
}

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  i64 p = power(b, c, MOD-1);
  i64 ans = power(a, p, MOD);
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
