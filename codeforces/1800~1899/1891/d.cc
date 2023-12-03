#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr i64 MOD = 1000000007;

i64 count(i64 x) {
  i64 ans = 0;
  for (int y = 2; (1LL << y) <= x; ++y) {
    u64 l = 1LL << y;
    u64 r = min(x, (1LL << (y+1))-1);
    u64 z = 0;
    u64 xx = 1;
    while (xx * y <= l) {
      z++;
      xx *= y;
    }

    if (r < xx * y) {
      ans += (r - l + 1) * z;
      ans %= MOD;
    } else {
      ans += (r - xx * y + 1) * (z+1);
      ans %= MOD;
      ans += (xx * y - l) * z;
      ans %= MOD;
    }
    // cout << "y=" << y << " ";
    // cout << "z=" << z << endl;
  }
  // cout << "x=" << x << ", ans=" << ans << endl;
  return ans;
}

void solve() {
  i64 l = 0, r = 0;
  cin >> l >> r;

  i64 ans = count(r) - count(l-1);
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
