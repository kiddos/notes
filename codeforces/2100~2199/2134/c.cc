#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  i64 ans = 0;
  for (int i = 2; i <= n; i += 2) {
    i64 even = a[i];
    i64 odd = a[i-1] + (i+1 <= n ? a[i+1] : 0);
    if (even < odd) {
      i64 extra = odd - even;
      if (i+1 <= n) {
        i64 remove = min(extra, a[i+1]);
        a[i+1] -= remove;
        extra -= remove;
        ans += remove;
      }

      if (extra) {
        i64 remove = min(extra, a[i-1]);
        a[i-1] -= remove;
        extra -= remove;
        ans += remove;
      }
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
