#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> x[i];
  }

  int m = 0;
  cin >> m;
  vector<int> b(m);
  vector<i64> y(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> y[i];
  }

  map<int, i64> first_has;
  for (int i = 0; i < n; ++i) {
    first_has[a[i]] = x[i];
  }

  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    if (first_has.count(b[i])) {
      ans += max(first_has[b[i]], y[i]);
      first_has.erase(b[i]);
    } else {
      ans += y[i];
    }
  }

  for (auto& [ai, xi] : first_has) {
    ans += xi;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
