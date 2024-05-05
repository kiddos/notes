#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 H = 0;
  cin >> n >> H;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());
  i64 two = a[0] + a[1];
  if (H <= a[0]) {
    cout << "1" << endl;
  } else if (H <= two) {
    cout << "2" << endl;
  } else {
    i64 ans = H / two * 2;
    i64 left = H % two;
    if (left > 0) {
      if (left <= a[0]) {
        ans++;
      } else {
        ans += 2;
      }
    }
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
