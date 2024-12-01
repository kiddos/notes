#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i =0; i < n; ++i) {
    cin >> a[i];
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i+1 < n) {
      ans = max(ans, a[i] * a[i+1]);
    }
    if (i > 0) {
      ans = max(ans, a[i] * a[i-1]);
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