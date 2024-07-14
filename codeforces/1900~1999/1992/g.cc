#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 5000;
constexpr int MOD = 1e9 + 7;
vector<i64> f(MAX_N+1, 1);
vector<i64> inv_f(MAX_N+1, 1);

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

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  inv_f[MAX_N] = power(f[MAX_N], MOD-2);
  for (int i = MAX_N-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

i64 C(int n, int k) {
  if (k > n) {
    return 0;
  }
  i64 ans = f[n];
  ans *= inv_f[k];
  ans %= MOD;
  ans *= inv_f[n-k];
  ans %= MOD;
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;

  auto select = [&](int n, int l, int h) -> i64 {
    if (n == 0) {
      return 1;
    }
    if (l > h) {
      return 0;
    }
    // cout << "C(" << h-l+1 << ", " << n << ") = " << C(h-l+1, n) << endl;
    return C(h-l+1, n);
  };

  i64 ans = 1;
  for (int k = 2; k <= n+1; ++k) {
    for (int mex = k; mex <= n+k; ++mex) {
      // int total = k-1;
      // int less = mex - (k-1);
      // int greater = total - less;
      if (mex-k <= k-1) {
        // cout << "mex=" << mex << ", k=" << k << ", size=" << k-1 << endl;
        // cout << "select " << mex-k << " numbers from 1~" << min(mex-1, n) << endl;
        // cout << "ans select " << k-1 - (mex-k) << " numbers from " << mex+1 << "~" << n << endl;
        i64 result = select(mex - k, 1, min(mex-1, n));
        result *= select(k - 1 - (mex - k), mex+1, n);
        result %= MOD;
        result *= mex;
        result %= MOD;
        ans += result;
        ans %= MOD;
      }
    }
    // cout << endl;
  }

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
