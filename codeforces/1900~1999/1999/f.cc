#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 1000000007;
vector<i64> f(MAX_N + 1, 1);
vector<i64> inv_f(MAX_N + 1, 1);

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
  inv_f[MAX_N] = power(f[MAX_N], MOD - 2);

  for (int i = MAX_N - 1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

i64 C(i64 n, i64 k) {
  if (k > n) return 0;

  i64 ans = f[n];
  ans *= inv_f[k];
  ans %= MOD;
  ans *= inv_f[n-k];
  ans %= MOD;
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ones = 0;
  for (int i = 0; i < n; ++i) {
    ones += a[i];
  }
  int zeros = n - ones;

  i64 ans = 0;
  for (int j = (k+1) / 2; j <= k; ++j) {
    ans += C(ones, j) * C(zeros, k-j);
    ans %= MOD;
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
