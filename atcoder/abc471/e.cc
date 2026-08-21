#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

//   (a1 + a2 + ... + an) ^ 2
// = a1^2 + a2^2 + ... + an^2 + sum of (ai * aj) * 2
// so we will need C(n-1, k-1) * (sum of ai^2) + C(n-2,k-2) * sum of (ai * aj) * 2
// how to compute sum of (ai * aj)
// we can first compute (a1 + a2 + ... + an) ^ 2
// and compute sum of (sum of ai^2)
// we can get sum of (ai * aj) * 2


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
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

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

  auto C = [&](int N, int K) -> i64 {
    i64 ans = f[N];
    ans *= inv_f[K];
    ans %= MOD;
    ans *= inv_f[N-K];
    ans %= MOD;
    return ans;
  };

  i64 square_sum = 0;
  for (int i = 0; i < n; ++i) {
    square_sum += (a[i] * a[i]) % MOD;
    square_sum %= MOD;
  }

  i64 sum = accumulate(a.begin(), a.end(), 0LL) % MOD;
  i64 sum_square = (sum * sum) % MOD;

  i64 ans = square_sum * C(n-1, k-1);
  ans %= MOD;
  i64 m = (sum_square - square_sum) % MOD;
  m = (m + MOD) % MOD;
  if (k >= 2) {
    ans += (C(n-2, k-2) * m) % MOD;
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
