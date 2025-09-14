#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  constexpr int MOD = 1e9 + 7;
  i64 ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     for (int k = 0; k < n; ++k) {
  //       i64 and_val = (x[i] & x[j]);
  //       i64 or_val = (x[j] | x[k]);
  //       ans += ((and_val % MOD) * (or_val % MOD)) % MOD;
  //       ans %= MOD;
  //     }
  //   }
  // }
  vector<int> bit_count(60);
  for (int b = 0; b < 60; ++b) {
    for (int i = 0; i < n; ++i) {
      if (x[i] & (1LL<<b)) {
        bit_count[b]++;
      }
    }
  }

  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < 60; ++b) {
      if (x[i] & (1LL<<b)) {
        i64 val = (1LL<<b);
        val %= MOD;
        val *= bit_count[b];
        val %= MOD;

        a[i] += val;
        a[i] %= MOD;
      }
    }
  }

  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += x[i];
    sum %= MOD;
  }

  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    i64 val = x[i] % MOD;
    val *= n;
    val %= MOD;
    val += sum;
    val %= MOD;
    val -= a[i];
    val %= MOD;
    val = (val + MOD) % MOD;

    b[i] = val;
  }

  for (int i = 0; i < n; ++i) {
    ans += (a[i] * b[i]) % MOD;
    ans %= MOD;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
