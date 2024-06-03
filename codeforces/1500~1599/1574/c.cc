#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m = 0;
  cin >> m;
  vector<i64> x(m), y(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
  }

  set<i64> s(a.begin(), a.end());
  i64 a_sum = accumulate(a.begin(), a.end(), 0LL);
  for (int i = 0; i < m; ++i) {
    i64 ans = numeric_limits<i64>::max();
    // send a hero with strength >= x
    auto it = s.lower_bound(x[i]);
    if (it != s.end()) {
      i64 rest_a = a_sum - *it;
      i64 coins = max(0LL, y[i] - rest_a);
      ans = min(ans, coins);
    }
    // or send a hero with strength < x
    it = s.upper_bound(x[i]-1);
    if (it != s.begin()) {
      --it;
      i64 rest_a = a_sum - *it;
      i64 coins = (x[i] - *it) + max(0LL, y[i] - rest_a);
      ans = min(ans, coins);
    }
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
