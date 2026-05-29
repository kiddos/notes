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
    x = (x * x);
    x %= MOD;
  }
  return ans;
}

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  vector<i64> inv_f(n+1, 1);
  inv_f[n] = power(f[n], MOD-2);
  for (int i = n-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int N, int K) -> i64{
    i64 ans = f[N];
    ans *= inv_f[K];
    ans %= MOD;
    ans *= inv_f[N-K];
    ans %= MOD;
    return ans;
  };

  i64 ans = m;
  for (int t = 0; t < k; ++t) {
    ans *= (m-1);
    ans %= MOD;
  }
  ans *= C(n-1, k);
  ans %= MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
