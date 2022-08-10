#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int extended_euclidean(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1 = 0, y1 = 0;
  int d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

ll pow(ll a, int n, int MOD) {
  a %= MOD;
  ll output = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      output = (output * a) % MOD;
    }
    n >>= 1;
    a = (a * a) % MOD;
  }
  return output;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MOD = 1e9 + 7;

  const int n = 10000;
  vector<ll> f(n + 1, 1);
  for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] * i) % MOD;

  vector<ll> inv(n + 1, 1);
  inv[n] = pow(f[n], MOD - 2, MOD);
  for (int i = n - 1; i >= 1; --i) inv[i] = (inv[i + 1] * (i + 1)) % MOD;

  vector<ll> inv2(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    int x = 0, y = 0;
    extended_euclidean(f[i], MOD, x, y);
    inv2[i] = (x % MOD + MOD) % MOD;
  }

  for (int i = 1; i <= n; ++i) {
    assert(inv[i] == inv2[i]);
  }
  return 0;
}
