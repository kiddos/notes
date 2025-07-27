#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  // p[i] / p[i-1] <= k / 100
  // => p[i] * 100 <= k * (p[i-1] + prefix)
  // => k * prefix >= p[i] * 100 - k * p[i-1]
  vector<i64> require_prefix(n);
  for (int i = 1; i < n; ++i) {
    i64 temp = p[i] * 100 - k * p[i-1];
    require_prefix[i-1] = (temp + k - 1) / k;
  }

  i64 prefix = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (prefix < require_prefix[i]) {
      ans += require_prefix[i] - prefix;
      prefix = require_prefix[i];
    }
    prefix += p[i];
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
