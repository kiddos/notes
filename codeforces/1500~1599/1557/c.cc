#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 1e9 + 7;
vector<i64> f(MAX_N+1, 1);
vector<i64> inv_f(MAX_N+1, 1);
vector<i64> p2(MAX_N+1, 1);

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  // ax + by = g
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

i64 mod_inv(i64 b) {
  i64 x = 0, y = 0;
  extended_euclidean(b, MOD, x, y);
  x %= MOD;
  return (x + MOD) % MOD;
}

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  inv_f[MAX_N] = mod_inv(f[MAX_N]);
  for (int i = MAX_N-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  for (int i = 1; i <= MAX_N; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }
}

i64 C(i64 n, i64 k) {
  i64 ans = f[n];
  ans *= inv_f[n-k];
  ans %= MOD;
  ans *= inv_f[k];
  ans %= MOD;
  return ans;
}

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
  int n = 0, k = 0;
  cin >> n >> k;

  i64 single_bit = 1;
  for (int i = 2; i < n; i += 2) {
    single_bit += C(n, i);
    single_bit %= MOD;
  }

  vector<i64> dp(2, 1);
  for (int j = k; j >= 1; --j) {
    vector<i64> dp2(2);
    dp2[0] = dp[0] * p2[n];
    dp2[1] = dp[1] * (single_bit + (n % 2));
    if (n % 2 == 0) {
      dp2[1] += dp[0];
    }
    dp2[0] %= MOD;
    dp2[1] %= MOD;
    dp = std::move(dp2);
  }

  i64 ans = dp[1];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
