#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  i64 ans = 0;
  for (int i = 0; i < 2 * n; i += 2) {
    ans += a[i];
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
