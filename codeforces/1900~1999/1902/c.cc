#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int max_val = *max_element(a.begin(), a.end());
  set<int> s;
  for (int i = 1; i <= n; ++i) s.insert(i);

  int g = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != max_val) {
      int diff = max_val - a[i];
      g = gcd(g, diff);
    }
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != max_val) {
      int diff = max_val - a[i];
      int op = diff / g;
      ans += diff / g;
      s.erase(op);
    }
  }

  ans += *s.begin();
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
