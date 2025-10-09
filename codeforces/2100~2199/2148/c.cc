#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1), b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }

  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] == b[i-1]) {
      int diff = a[i] - a[i-1];
      if (diff % 2 == 0) {
        ans += diff;
      } else {
        ans += diff-1;
      }
    } else {
      int diff = a[i] - a[i-1];
      if (diff % 2 == 1) {
        ans += diff;
      } else {
        ans += diff-1;
      }
    }
  }
  if (a.back() != m) {
    ans += m-a.back();
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
