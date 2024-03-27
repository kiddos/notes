#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  vector<int> c(m);
  for (int i = 0; i < m; ++i) cin >> c[i];

  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int max_c = k - b[i];
    int idx = upper_bound(c.begin(), c.end(), max_c) - c.begin();
    ans += idx;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}