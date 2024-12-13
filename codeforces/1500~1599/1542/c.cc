#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;
constexpr i64 MAX_N = 1e16;

unordered_map<int,int> get_factors(int x) {
  unordered_map<int, int> f;
  for (int p = 2; p*p <= x; ++p) {
    while (x % p == 0) {
      f[p]++;
      x /= p;
    }
  }
  if (x > 1) {
    f[x]++;
  }
  return f;
}

vector<i64> p = {1};

void precompute() {
  // observe the pattern:
  // f = 2, 3, 2, 3, 2, 4,
  //     2, 3, 2, 3, 2, 5,
  //     2, 3, 2, 3, 2, 4,
  //     2, 3, 2, 3, 2, 5,
  //     2, 3, 2, 3, 2, 4,
  //     2, 3, 2, 3, 2, 5,
  //     2, 3, 2, 3, 2, 4,
  //     2, 3, 2, 3, 2, 5,
  //     2, 3, 2, 3, 2, 4,
  //     2, 3, 2, 3, 2, 7,
  //     ...
  // constexpr int observe_size = 1000000;
  // vector<i64> f(observe_size+1);
  // for (int i = 1; i <= observe_size; ++i) {
  //   for (int j = 1; j <= observe_size * 2; ++j) {
  //     if (i % j != 0) {
  //       f[i] = j;
  //       break;
  //     }
  //   }
  // }
  //
  // set<int> found;
  // for (int i = 1; i <= observe_size; ++i) {
  //   if (!found.count(f[i])) {
  //     cout << i << endl;
  //     found.insert(f[i]);
  //   }
  //   // cout << f[i] << " ";
  // }

  // so base = 2
  // every 2 + 1
  // every 6 + 1
  // every 12 + 1
  // every 60 + 1
  // every 420 + 1
  // every 820 + 1
  // every 2520 + 1
  // ...
  map<int, int> factors;
  i64 x = 1;
  i64 next_f = 2;
  while (x <= MAX_N) {
    unordered_map<int, int> primes = get_factors(next_f);
    i64 mul = 1;
    for (auto [p, count] : primes) {
      while (factors[p] < count) {
        factors[p]++;
        mul *= p;
      }
    }
    x *= mul;
    p.push_back(x);
    next_f++;
  }
  // for (i64 x : p) {
  //   cout << x << " ";
  // }
  // cout << endl;
}

void solve() {
  i64 n = 0;
  cin >> n;
  i64 ans = (n * 2) % MOD;
  for (int i = 1; i < (int)p.size(); ++i) {
    ans += n / p[i];
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
