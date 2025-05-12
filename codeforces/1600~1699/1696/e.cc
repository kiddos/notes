#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;

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
  int n = 0;
  cin >> n;
  vector<i64> a(n+2);
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }
  int max_a = *max_element(a.begin(), a.end());
  int max_n = max_a + n + 1;
  vector<i64> f(max_n+1, 1);
  for (int i = 2; i <= max_n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  vector<i64> inv_f(max_n+1, 1);
  inv_f[max_n] = power(f[max_n], MOD-2);
  for (int i = max_n-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int n, int k) -> i64 {
    i64 ans = f[n];
    ans *= inv_f[n-k];
    ans %= MOD;
    ans *= inv_f[k];
    ans %= MOD;
    return ans;
  };

  i64 ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (a[i] < 1) {
      break;
    }
    ans += C(i + a[i], i+1);
    // cout << "C(" << i+a[i] << "," << i+1 << ")=" << C(i + a[i], i+1) << endl;
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
