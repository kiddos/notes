#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;
constexpr int MAX_N = 100000;

vector<i64> f(MAX_N * 2+1, 1);

void precompute() {
  for (int i = 2; i <= MAX_N*2; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
}

constexpr i64 power(i64 x, i64 n) {
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
  int n = 0;
  cin >> n;
  i64 ans = f[n * 2] * power(2, MOD-2);
  ans %= MOD;
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
