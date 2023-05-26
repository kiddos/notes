#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  unordered_map<int, int> primes;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    for (int d = 2; d*d <= x; ++d) {
      if (x % d == 0) {
        while (x % d == 0) {
          primes[d]++;
          x /= d;
        }
      }
    }
    if (x > 1) {
      primes[x]++;
    }
  }

  int ans = 0;
  int left_over = 0;
  for (auto& [p, count] : primes) {
    ans += count / 2;
    left_over += count % 2;
  }
  ans += left_over / 3;
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
