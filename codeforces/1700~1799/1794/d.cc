#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// answer should be the sum of possible prime of n! / (b1! * b2! * b3! * ...) * (c1! * c2! * c3! * ...)
// where b is the number of occurance of non primes
// ans c is the number of occurance of primes
//
// the difficult part is to know how to calculate the sum of possible primes of
// 1 / (c1! * c2! * c3! * ...)
//
// the editorial use dp(x, y)
// which means the the sum considering only the x-th primes and
// there are y primes that needs to be chosen


constexpr int MAX_VAL = 1e6;
constexpr int MAX_N = 5000;
constexpr int MOD = 998244353;

vector<bool> is_prime(MAX_VAL+1, true);
vector<i64> f(MAX_N+1, 1);
vector<i64> f_inv(MAX_N+1, 1);

i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    x = x * x;
    x %= mod;
    n >>= 1;
  }
  return ans;
}

void precompute() {
  is_prime[1] = false;
  for (int i = 2; i <= MAX_VAL; ++i) {
    if (is_prime[i]) {
      for (int j = i*2; j <= MAX_VAL; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  f_inv[MAX_N] = power(f[MAX_N], MOD-2, MOD);
  for (int i = MAX_N-1; i >= 1; --i) {
    f_inv[i] = f_inv[i+1] * (i+1);
    f_inv[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  map<int,int> freq;
  for (int i = 0; i < 2 * n; ++i) {
    int a = 0;
    cin >> a;
    freq[a]++;
  }

  vector<pair<int,int>> nums(freq.begin(), freq.end());

  vector<pair<int,int>> primes;
  for (auto& [x, count] : nums) {
    if (is_prime[x]) {
      primes.push_back({x, count});
    }
  }

  vector<vector<i64>> memo(n*2+1, vector<i64>(n*2+1, -1));
  function<i64(int,int)> dp = [&](int x, int y) -> i64 {
    i64& ans = memo[x][y];
    if (ans >= 0) {
      return ans;
    }

    if (x == (int)primes.size()) {
      return ans = (y == 0);
    }

    // dont use the x-th prime
    ans = f_inv[primes[x].second] * dp(x+1, y) % MOD;

    if (y > 0) {
      // use the x-th prime
      ans = ans + f_inv[primes[x].second - 1] * dp(x+1, y-1) % MOD;
    }
    return ans;
  };

  i64 ans = dp(0, n);

  for (auto& [x, count] : nums) {
    if (!is_prime[x]) {
      ans = ans * f_inv[count];
      ans %= MOD;
    }
  }

  ans = ans * f[n];
  ans %= MOD;

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  solve();
  return 0;
}
