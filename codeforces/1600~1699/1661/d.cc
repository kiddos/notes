#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [5, 4, 6]
// [0, 0, 0]
// [5, 10, 15]
//
// [1, 2, 3, 2, 2, 3]
// [0, 0, 0, 0, 0, 0]
// [1, 2, 3, 0, 0, 0]
// [1, 2, 3, 2, 4, 6]
//
//
// [50, 17, 81, 25, 42, 39, 96]
// [ 0,  0,  0,  0, 32, 64, 96] + 32
// [ 0,  0,  4,  8, 44, 64, 96] + 4
// [ 0,  6, 12, 26, 44, 64, 96] + 6
// [ 50,106,231, 26, 44, 64, 96] + 50
//
//
// k = 4
// [a1, a2, a3, a4, a5, a6, a7, a8]
// for a8
// a8 = (b8 + k - 1) / k
//
// for a7
// added = a8 * k-1
// a7 = (max(b7 - added, 0) + k - 1) / k
//
// for a6
// added = a8 * (k - 2) + a7 * (k-1)
// a6 = (max(b6 - added, 0) + k - 1) / k

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> b(n+1);
  for (int i = 1; i <= n; ++i) cin >> b[i];

  vector<i64> suffix(n+2);
  vector<i64> a(n+1);
  i64 window = 0;
  i64 ans1 = 0;
  i64 ans2 = 0;
  for (int i = n; i >= 1; --i) {
    window -= suffix[i+1] - suffix[min(i + k, n+1)];
    if (i+k <= n) {
      window -= a[i+k];
    }
    // cout << "i=" << i << ", window=" << window << endl;
    if (i <= k) {
      if (window < b[i]) {
        ans2 = max(ans2, (b[i] - window + i - 1) / i);
      }
    } else {
      if (window < b[i]) {
        a[i] += (b[i] - window + k - 1) / k;
        ans1 += a[i];
        // cout << "added: " << a[i] << endl;
      }
    }
    suffix[i] = suffix[i+1] + a[i];
    window += a[i] * k;
  }

  i64 ans = ans1 + ans2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
