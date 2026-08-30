#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 72 = 2 ^ 3 * 3 ^ 2
// 2, 3, 4, 6, 8, 9, 12, 18, 24, 36, 72
// 2 = 2
// 3 = 3,
// 4 = 2 * 2
// 6 = 2 * 3
// 8 = 2 * 2 * 2
// 9 = 3 * 3
// 12 = 2 * 2 * 3
// 18 = 2 * 3 * 3
// 24 = 2 * 2 * 2 * 3
// 36 = 2 * 2 * 3 * 3
// 72 = 2 * 2 * 2 * 3 * 3

void solve() {
  int n = 0;
  cin >> n;
  int x = n;
  vector<int> primes;
  for (int d = 2; d *d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      primes.push_back(d);
    }
  }
  if (x > 1) {
    primes.push_back(x);
  };
  int total_prime = primes.size();

  sort(primes.begin(), primes.end());
  primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
  int unique_primes = primes.size();

  int ans = total_prime + unique_primes - 1;
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
