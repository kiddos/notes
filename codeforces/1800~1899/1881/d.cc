#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> factors;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    for (int d = 2; d * d <= x; ++d) {
      while (x % d == 0) {
        x /= d;
        factors[d]++;
      }
    }
    if (x > 1) {
      factors[x]++;
    }
  }

  for (auto& [f, c] : factors) {
    if (c % n != 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
