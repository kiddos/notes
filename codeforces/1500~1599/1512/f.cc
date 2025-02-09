#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = n-1;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  i64 ans = numeric_limits<i64>::max();
  i64 coins = 0;
  i64 upgrade_days = 0;
  for (int i = 0; i < n; ++i) {
    i64 need = c - coins;
    i64 days = (need + a[i] - 1) / a[i];
    ans = min(ans, days + upgrade_days);
    // cout << "i=" << i << ":" << days + upgrade_days << endl;

    if (i+1 < n) {
      i64 take_course = max(b[i] - coins, 0LL);
      i64 upgrade = (take_course + a[i]-1) / a[i];
      upgrade_days += upgrade + 1;
      coins = coins + upgrade * a[i] - b[i];
      // cout << "coins=" << coins << endl;
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
