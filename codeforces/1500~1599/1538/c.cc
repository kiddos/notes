#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 l = 0, r = 0;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int L = i+1, R = n-1;
    int i1 = -1;
    while (L <= R) {
      int mid = L + (R-L) / 2;
      if (a[mid] + a[i] >= l) {
        R = mid-1;
        i1 = mid;
      } else {
        L = mid+1;
      }
    }
    L = i+1;
    R = n-1;
    int i2 = -1;
    while (L <= R) {
      int mid = L + (R-L) / 2;
      if (a[mid] + a[i] <= r) {
        L = mid + 1;
        i2 = mid;
      } else {
        R = mid - 1;
      }
    }
    if (i1 >= 0 && i2 >= 0) {
      int len = i2 - i1 + 1;
      ans += len;
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
