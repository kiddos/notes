#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// (1, 2) (1, 2) => 1 + 2
// (1, 2) (1, 3) => 1 + 0
// (1, 2) (2, 3) => 1 + 0
// (1, 3) (1, 2) => 0 + 1
// (1, 3) (1, 3) => 0 + 0
// (1, 3) (2, 3) => 0 + 0
// (2, 3) (1, 2) => 0 + 1
// (2, 3) (1, 3) => 0 + 0
// (2, 3) (2, 3) => 0 + 0
// => 7 / 9

constexpr int MAX_K = 200000;
constexpr int MOD = 1000000007;

vector<i64> f(MAX_K+1, 1);
vector<i64> inv_f(MAX_K+1);

i64 power(i64 x, i64 n) {
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

void precompute() {
  for (int i = 2; i <= MAX_K; ++i) {
    f[i] = (f[i-1] * i) % MOD;
  }
  inv_f[MAX_K] = power(f[MAX_K], MOD-2);
  for (int i = MAX_K-1; i >= 0; --i) {
    inv_f[i] = (inv_f[i+1] * (i+1)) % MOD;
  }
}

void solve() {
  i64 n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<array<i64,3>> pairs;

  for (int i = 0; i < m; ++i) {
    i64 a = 0, b = 0, f = 0;
    cin >> a >> b >> f;
    pairs.push_back({a, b, f});
  }

  i64 n_pairs = (i64)n * (n-1) / 2;
  i64 pk = power(n_pairs % MOD, k);
  i64 inv_n_pairs = power(n_pairs % MOD, MOD-2);

  auto combination = [&](int n, int k) {
    i64 ans = f[n] * inv_f[k];
    ans %= MOD;
    ans *= inv_f[n-k];
    ans %= MOD;
    return ans;
  };

  i64 ans = 0;
  for (auto& [a, b, f] : pairs) {
    i64 base = ((f * k) % MOD);
    base *= inv_n_pairs;
    base %= MOD;
    ans += base;
    ans %= MOD;
  }

  i64 inv_pk = power(pk, MOD-2);
  for (i64 x = 2; x <= k; ++x) {
    i64 rest = x * (x-1) / 2;
    rest %= MOD;
    rest *= combination(k, x);
    rest %= MOD;
    rest *= power((n_pairs-1+MOD) % MOD, k-x); 
    rest %= MOD;
    rest *= inv_pk;
    rest %= MOD;
    ans += rest * m;
    ans %= MOD;
  }

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
