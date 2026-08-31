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

void mod_sub(i64& x, i64 y) {
  y %= MOD;
  x -= y;
  x %= MOD;
  x += MOD;
  x %= MOD;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
    p.back() %= MOD;
  }

  vector<i64> inv_div(n+1);
  for (int i = 1; i <= n; ++i) {
    inv_div[i] = power(i, MOD-2);
  }

  vector<i64> p_inv = inv_div;
  for (int i = 2; i <= n; ++i) {
    p_inv[i] += p_inv[i-1];
    p_inv[i] %= MOD;
  }

  i64 ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j <= i; ++j) {
  //     ans += (p[i+1] - p[j]) * inv_div[i-j+1];
  //     ans %= MOD;
  //   }
  // }
  for (int i = 0; i < n; ++i) {
    ans += (p[i+1] * p_inv[i+1]) % MOD;
    ans %= MOD;
  }
  for (int i = 0; i < n; ++i) {
    mod_sub(ans, p[i] * p_inv[n-i]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
