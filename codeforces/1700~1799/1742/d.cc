#include <bits/stdc++.h>

using namespace std;

unordered_set<int> get_factors(int x) {
  unordered_set<int> f;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      while (x % d == 0) {
        x /= d;
      }
      f.insert(d);
    }
  }

  if (x > 1) {
    f.insert(x);
  }
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> index(1001, -1);
  for (int i = 0; i < n; ++i) {
    index[a[i]] = max(index[a[i]], i+1);
  }

  int ans = -1;
  for (int a = 1; a <= 1000; ++a) {
    if (index[a] < 0) continue;
    for (int b = a; b <= 1000; ++b) {
      if (index[b] < 0) continue;

      int g = gcd(a, b);
      if (g > 1) continue;
      ans = max(ans, index[a] + index[b]);
    }
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
