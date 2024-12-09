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
  int ans = 0;
  for (i64 i = 1; i <= n; ++i) {
    i64 x = (i * 2 + a[i] - 1) / a[i];
    i64 j0 = a[i] * x - i;
    // cout << "x=" << x <<  ",i=" << i << ",j0=" << j0 << endl;
    for (int j = j0; j <= n; j += a[i]) {
      if (i != j && a[j] * a[i] == j + i) {
        ans++;
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
