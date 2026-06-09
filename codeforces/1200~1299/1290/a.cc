#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  if (k+1 >= m) {
    for (int i = 0; i < m; ++i) {
      ans = max(ans, a[i]);
    }
    for (int i = n-1; i >= n-m; --i) {
      ans = max(ans, a[i]);
    }
  } else {
    for (int l1 = 0; l1 <= k; ++l1) {
      int take_right = k - l1;
      int r1 = n-1-take_right;
      int arbitrary = m - k - 1;
      int min_val = numeric_limits<int>::max();
      // cout << "l1=" << l1 << ",r1=" << r1 << " more=" << arbitrary << endl;
      for (int t = 0; t <= arbitrary; ++t) {
        int l2 = l1 + t;
        int r2 = r1 - (arbitrary - t);
        // cout << "l2=" << l2 << ",r2=" << r2 << endl;
        min_val = min(min_val, max(a[l2], a[r2]));
      }
      ans = max(ans, min_val);
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
