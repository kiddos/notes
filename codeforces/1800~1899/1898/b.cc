#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 last = a.back();
  i64 ans = 0;
  for (int i = n-2; i >= 0; --i) {
    if (a[i] > last) {
      i64 l = 2, r = a[i];
      i64 div = r;
      while (l <= r) {
        i64 mid = l + (r-l) / 2;
        i64 d = a[i] / mid;
        i64 new_last = d + (a[i] % mid == 0 ? 0 : 1);
        if (new_last <= last) {
          div = mid;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }
      ans += div - 1;
      last = a[i] / div;
      // cout << "i = " << i << ", div=" << div << ", last=" << last << endl;
    } else {
      last = min(last, a[i]);
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
