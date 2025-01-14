#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

vector<i64> get_prime_factors(i64 x) {
  vector<i64> p;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      while (x % d == 0) {
        p.push_back(d);
        x /= d;
      }
    }
  }
  if (x > 1) {
    p.push_back(x);
  }
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  return p;
}

i64 inclusion_exclusion(vector<i64>& primes, int base, int m) {
  int n = primes.size();
  vector<i64> vals = primes;
  for (int i = 0; i < n; ++i) {
    vals[i] *= base;
  }

  i64 ans = 0;
  int size = 1 << n;
  for (int mask = 1; mask < size; ++mask) {
    i64 l = 1;
    int bit_count = 0;
    for (int b = 0; b < n; ++b) {
      if (mask & (1<<b)) {
        l = lcm(l, vals[b]);
        bit_count++;
      }
    }

    i64 count = m / l;
    if (bit_count % 2 == 1) {
      ans += count;
      ans %= MOD;
      // cout << "-" << count << endl;
    } else {
      ans -= count;
      ans %= MOD;
      ans = (ans + MOD) % MOD;
      // cout << "+" << count << endl;
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> dp(n);
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i-1] % a[i] != 0) {
      cout << "0" << endl;
      return;
    }

    i64 div = a[i-1] / a[i];
    vector<i64> prime_factors = get_prime_factors(div);
    i64 result = inclusion_exclusion(prime_factors, a[i], m);
    // cout << "+" << m / a[i] << endl;
    dp[i] = m / a[i] - result;
    dp[i] %= MOD;
    dp[i] = (dp[i] + MOD) % MOD;
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
  i64 ans = 1;
  for (int i = 0; i < n; ++i) {
    ans *= dp[i];
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
