#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
constexpr int MAX_N = 200000;

vector<i64> f(MAX_N+1, 1);
vector<i64> inv_f(MAX_N+1, 1);

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
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int available = 0;
  i64 ans = 1;
  for (int i = n; i >= 1; --i) {
    if (n % 2 == 1 && i == (n+1) / 2) {
      available++;
    } else if (i * 2 <= n) {
      available += 2;
    }

    if (available < a[i]) {
      cout << "0" << endl;
      return;
    }
    ans *= C(available, a[i]);
    ans %= MOD;
    available -= a[i];
  }

  if (available != 0) {
    cout << "0" << endl;
  } else {
    cout << ans << endl;
  }
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
