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
    x = x * x;
    x %= MOD;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;

  vector<i64> f(n+1, 1);
  vector<i64> inv_f(n+1, 1);

  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  inv_f[n] = power(f[n], MOD-2);
  for (int i = n-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto c = [&](i64 n, i64 k) -> i64 {
    i64 ans = f[n];
    ans *= inv_f[k];
    ans %= MOD;
    ans *= inv_f[n-k];
    ans %= MOD;
    return ans;
  };

  vector<vector<i64>> dp(n+1, vector<i64>(x+1));
  dp[n][0] = 1;
  for (int alive = n; alive >= 2; --alive) {
    for (int damage = 0; damage < x; ++damage) {
      int d2 = min(x, alive + damage - 1);
      i64 damage_power = 1;
      for (int a2 = alive; a2 >= 0; --a2) {
        i64 dp2 = dp[alive][damage];
        dp2 *= c(alive, alive - a2);
        dp2 %= MOD;
        dp2 *= damage_power;
        dp2 %= MOD;

        damage_power *= (d2 - damage);
        damage_power %= MOD;

        dp[a2][d2] += dp2;
        dp[a2][d2] %= MOD;
      }
    }
  }

  i64 ans = 0;
  for (int d = 0; d <= x; ++d) {
    ans += dp[0][d];
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
