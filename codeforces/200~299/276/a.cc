#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> f(n), t(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i] >> t[i];
  }

  i64 ans = numeric_limits<int>::min();
  for (int i = 0; i < n; ++i) {
    i64 joy = f[i];
    if (t[i] > k) {
      joy = f[i] - (t[i] - k);
    }
    ans = max(ans, joy);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
