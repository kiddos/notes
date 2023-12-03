#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 1; i < n; ++i) a[i] += a[i-1];

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 l = 0, r = x;
    i64 pack = 0;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      if (a[i] + (i+1) * mid <= x) {
        pack = mid + 1;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    ans += pack;
    // cout << "pack=" << pack << endl;
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
