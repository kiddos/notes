#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;

  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n == 1) {
    i64 ans = a[0] + k - 1;
    cout << ans << endl;
    return;
  }

  if (k < n) {
    i64 sum = 0;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (i >= k) {
        sum -= a[i-k];
      }
      if (sum >= k-1) {
        ans = max(ans, sum);
      }
    }
    ans += k * (k-1) / 2;
    cout << ans << endl;
  } else if (k == n) {
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
    ans += k * (k-1) / 2;
    cout << ans << endl;
  } else {
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
    ans += (k-1 + k-n) * n / 2;

    cout << ans << endl;
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
