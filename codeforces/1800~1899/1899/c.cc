#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 current = 0;
  i64 ans = numeric_limits<i64>::min();
  for (int i = 0; i < n; ++i) {
    if (i == 0 || abs(a[i]) % 2 == abs(a[i-1]) % 2) {
      current = a[i];
    } else {
      current = max((i64)a[i], current + a[i]);
    }

    ans = max(ans, current);
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
