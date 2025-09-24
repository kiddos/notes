#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  x %= MOD;
  while (n > 0) {
    if (n & 1) {
      ans = (ans * x) % MOD;
    }
    x = (x * x) % MOD;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;

  vector<i64> fib(n+1);
  fib[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
    fib[i] %= MOD;
  }

  vector<i64> p2(n+1, 1);
  for (int i = 1; i <= n; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }

  i64 ans = fib[n] * power(p2[n], MOD-2);
  ans %= MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
