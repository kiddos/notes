#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

i64 inv_mod(i64 n, i64 mod) {
  i64 x = 0, y = 0;
  extended_euclidean(n, mod, x, y);
  return (x % mod + mod) % mod;
}

void solve() {
  int n = 0, p = 0;
  cin >> n >> p;

  vector<i64> f(n+1, 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= p;
  }
  vector<i64> inv_f(n+1, 1);
  inv_f[n] = inv_mod(f[n], p);
  for (int i = n-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= p;
  }

  auto C = [&](i64 N, i64 K) -> i64 {
    i64 ans = f[N];
    ans *= inv_f[K];
    ans %= p;
    ans *= inv_f[N-K];
    ans %= p;
    return ans;
  };

  i64 ans = 0;
  for (int len = 1; len <= (n+1) / 2; ++len) {
    for (int j = 0; j <= max(len-2, 0); ++j) {
      i64 ways = j == 0 ? 1 : C(len-2, j);
      i64 last = len - (n % 2);
      i64 add  = ways * f[n-min(len,2)-1-j];
      add %= p;
      add *= last;

      ans += add;
      ans %= p;
    }
  }
  ans *= n;
  ans %= p;

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
