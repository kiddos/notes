#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n, int mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  vector<i64> inv_f(n+1, 1);
  inv_f[n] = power(f[n], MOD-2, MOD);
  for (int i = n-1; i >= 0; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int n, int k) -> i64 {
    i64 ans = f[n];
    ans *= inv_f[n-k];
    ans %= MOD;
    ans *= inv_f[k];
    ans %= MOD;
    return ans;
  };

  i64 ans = 0;
  for (int i = 0; i <= min(k, n); ++i) {
    ans += C(n, i);
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
