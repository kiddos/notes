#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());
  for (int i = 1; i < n; ++i) {
    a[i] += a[i-1];
  }

  while (q-- > 0) {
    int x = 0;
    cin >> x;
    if (x > a.back()) {
      cout << "-1" << endl;
    } else {
      int l = 0, r = n-1;
      int ans = -1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        if (a[mid] >= x) {
          ans = mid + 1;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }

      cout << ans << endl;
    }
  }
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
