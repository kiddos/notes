#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<i64> prefix(n+2), suffix(n+2);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = max(prefix[i], a[i] + (n-i));
    suffix[i] = max(suffix[i], a[i] + i-1);
  }
  for (int i = 1; i <= n; ++i) {
    prefix[i] = max(prefix[i], prefix[i-1]);
  }
  for (int i = n; i >= 1; --i) {
    suffix[i] = max(suffix[i], suffix[i+1]);
  }
  i64 ans = numeric_limits<i64>::max();
  for (int i = 1; i <= n; ++i) {
    // cout << a[i] << ", " << prefix[i-1] << ", " << suffix[i+1] << endl;
    i64 max_val = max({a[i], prefix[i-1], suffix[i+1]});
    ans = min(ans, max_val);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
