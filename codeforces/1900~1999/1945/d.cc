#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<i64> s(n+1);
  for (int i = n-1; i >= 0; --i) {
    s[i] = min(b[i], a[i]) + s[i+1];
  }

  i64 ans = numeric_limits<i64>::max();
  for (int i = 0; i < m; ++i) {
    i64 bribe = a[i] + s[i+1];
    ans = min(ans, bribe);
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
