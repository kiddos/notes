#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  auto lcm = [&](i64 x, i64 y) -> i64 {
    return x * y / gcd(x, y);
  };

  i64 l = 1;
  for (int i = 0; i < n; ++i) {
    l = lcm(l, a[i]);
    if (l > a.back()) {
      cout << n << endl;
      return;
    }
  }

  set<i64> s(a.begin(), a.end());
  auto find_subseq = [&](int d) -> int {
    i64 l = 1;
    int len = 0;
    for (int i = 0; i < n; ++i) {
      if (d % a[i] == 0) {
        l = lcm(l, a[i]);
        len++;
      }
    }
    if (l == d) return len;
    return 0;
  };

  int ans = 0;
  for (int d = 1; d * d <= a.back(); ++d) {
    if (a.back() % d != 0) continue;

    if (!s.count(d)) {
      int len = find_subseq(d);
      ans = max(ans, len);
    }
    int d2 = a.back() / d;
    if (!s.count(d2)) {
      int len = find_subseq(d2);
      ans = max(ans, len);
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
