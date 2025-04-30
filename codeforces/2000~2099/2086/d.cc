#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_LEN = 500000 * 26;
constexpr int MOD = 998244353;
vector<i64> f(MAX_LEN+1, 1);
vector<i64> inv_f(MAX_LEN+1, 1);

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    x = (x * x) % MOD;
    n >>= 1;
  }
  return ans;
}

void precompute() {
  for (int i = 2; i <= MAX_LEN; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  inv_f[MAX_LEN] = power(f[MAX_LEN], MOD-2);
  for (int i = MAX_LEN-1; i >= 0; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

i64 C(int n, int k) {
  i64 ans = f[n];
  ans *= inv_f[n-k];
  ans %= MOD;
  ans *= inv_f[k];
  ans %= MOD;
  return ans;
}

void solve() {
  vector<int> c(26);
  for (int i = 0; i < 26; ++i) {
    cin >> c[i];
  }
  vector<int> p = {0};
  for (int i = 0; i < 26; ++i) {
    p.push_back(p.back() + c[i]);
  }
  int len = p.back();
  int even = len / 2;

  vector<vector<i64>> memo(26, vector<i64>(even+1, -1));
  function<i64(int,int)> dp = [&](int i, int e) -> i64 {
    int o = len - p[i] - e;
    if (i == 26) {
      return e == 0 && o == 0 ? 1 : 0;
    }

    if (c[i] == 0) {
      return dp(i+1, e);
    }

    if (memo[i][e] >= 0) {
      return memo[i][e];
    }

    i64 ans = 0;
    if (e >= c[i]) {
      ans += (dp(i+1, e-c[i]) * C(e, c[i])) % MOD;
      ans %= MOD;
    }
    if (o >= c[i]) {
      ans += (dp(i+1, e) * C(o, c[i])) % MOD;
      ans %= MOD;
    }
    return memo[i][e] = ans;
  };

  i64 ans = dp(0, even);
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
