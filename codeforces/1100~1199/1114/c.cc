#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

vector<i64> get_prime_factors(i64 x) {
  vector<i64> f;
  for (i64 d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      f.push_back(d);
      x /= d;
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  return f;
}

void solve() {
  u64 n = 0, b = 0;
  cin >> n >> b;
  vector<i64> primes = get_prime_factors(b);
  map<i64, int> prime_count;
  for (i64 p : primes) {
    prime_count[p]++;
  }
  u64 ans = numeric_limits<u64>::max();
  for (auto [prime, count] : prime_count) {
    u64 p = prime;
    u64 total = 0;
    while (true) {
      total += n / p;
      if (n / prime < p) {
        break;
      }
      p *= prime;
    }
    u64 max_can_get = total / count;
    ans = min(ans, max_can_get);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
