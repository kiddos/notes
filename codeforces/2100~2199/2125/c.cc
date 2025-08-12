#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 l = 0, r = 0;
  cin >> l >> r;
  vector<int> invalid_primes = {2, 3, 5, 7};
  int size = invalid_primes.size();
  int m = 1<<size;

  auto count_prefix = [&](i64 p) -> i64 {
    i64 remove = 0;
    for (int mask = 1; mask < m; ++mask) {
      int count = 0;
      i64 prod = 1;
      for (int b = 0; b < size; ++b) {
        if (mask & 1 << b) {
          prod *= invalid_primes[b];
          count++;
        }
      }
      if (count % 2 == 1) {
        remove += p / prod;
      } else {
        remove -= p / prod;
      }
    }
    return p - remove;
  };

  i64 ans = count_prefix(r) - count_prefix(l-1);
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
