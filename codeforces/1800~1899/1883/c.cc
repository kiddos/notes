#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int ans = k;
  if (k == 4) {
    int mod2 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == 0) {
        mod2++;
      }
    }
    ans = max(2 - mod2, 0);
    for (int i = 0; i < n; ++i) {
      if (a[i] % k != 0) {
        ans = min(ans, k - (a[i] % k));
      } else {
        ans = min(ans, 0);
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if (a[i] % k != 0) {
        ans = min(ans, k - (a[i] % k));
      } else {
        ans = min(ans, 0);
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
