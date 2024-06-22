#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 sum = 0;
  i64 max_val = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    max_val = max(max_val, a[i]);
    if (max_val == sum - max_val) {
      ans++;
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
