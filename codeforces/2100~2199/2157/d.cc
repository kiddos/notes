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
  // i64 ans = numeric_limits<i64>::max();
  // for (int p = l; p <= r; ++p) {
  //   i64 coins = 0;
  //   for (int i  = 0; i < n; ++i) {
  //     coins += abs(p - a[i]);
  //   }
  //   ans = min(ans, coins);
  // }
  // cout << ans << endl;

  sort(a.begin(), a.end());
  i64 x = a[n/2];
  if (x < l) {
    x = l;
  }
  if (x > r) {
    x = r;
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(a[i] - x);
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
