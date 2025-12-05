#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<i64> f(n+1);
  i64 sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += a[i];
    f[i] = (i64)i * i + i - sum;
  }
  i64 min_val = 0;
  i64 ans = sum;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sum + f[i] - min_val);
    min_val = min(min_val, f[i]);
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
