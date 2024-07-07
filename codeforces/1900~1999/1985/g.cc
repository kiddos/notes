#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n)  {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    n >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}

void solve() {
  i64 l = 0, r = 0, k = 0;
  cin >> l >> r >> k;

  i64 ans = power(9 / k + 1, r) - power(9 / k + 1, l);
  ans %= MOD;
  ans = (ans + MOD) % MOD;
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
