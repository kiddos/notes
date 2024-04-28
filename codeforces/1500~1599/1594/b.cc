#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    x *= x;
    x %= MOD;
    n >>= 1;
  }
  return ans;
}

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;

  i64 ans = 0;
  for (int i = 30; i >= 0; --i) {
    if (k & (1<<i)) {
      ans += power(n, i);
      ans %= MOD;
    }
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
