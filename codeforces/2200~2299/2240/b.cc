#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
i64 power(i64 x, i64 n) {
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
  i64 n = 0, m = 0, r = 0, c = 0;
  cin >> n >> m >> r >> c;
  i64 grid_size = r * c;
  i64 p2 = grid_size-1;
  p2 += (m-c) * (r-1);
  p2 += (n-r) * (c-1);
  i64 ans = power(2, p2);
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
