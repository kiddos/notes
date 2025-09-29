#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int idx = n;
  while (idx >= 1 && a[idx] == idx) {
    idx--;
  }

  vector<int> r(m);
  vector<double> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> r[i] >> p[i];
  }

  if (idx == 0) {
    cout << fixed << setprecision(6) << 1.0 << endl;
    return;
  }

  double ans = 0;
  double failed = 1.0;
  for (int i = 0; i < m; ++i) {
    if (r[i] >= idx) {
      ans += failed * p[i];
      failed *= (1.0-p[i]);
    }
  }
  cout << fixed << setprecision(6) << ans << endl;
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
