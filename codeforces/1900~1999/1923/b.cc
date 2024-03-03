#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  vector<i64> sum(n+1);
  for (int i = 0; i < n; ++i) {
    sum[abs(x[i])] += a[i];
  }
  i64 extra = 0;
  for (int i = 1; i <= n; ++i) {
    i64 damage = (i64)k + extra;
    if (damage < sum[i]) {
      cout << "NO" << endl;
      return;
    }
    extra = damage - sum[i];
  }
  cout << "YES" << endl;
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
