#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<i64> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<i64> without_rollback(n);
  vector<i64> with_rollback(n);
  for (int i = 0; i < n; ++i) {
    without_rollback[i] = a[i] * (b[i]-1);
    with_rollback[i] = a[i] * b[i] - c[i];
  }

  i64 total_without_rollback =
    accumulate(without_rollback.begin(), without_rollback.end(), 0LL);
  if (total_without_rollback >= x) {
    cout << "0" << endl;
    return;
  }

  i64 max_with_rollback =
    *max_element(with_rollback.begin(), with_rollback.end());
  if (max_with_rollback <= 0) {
    cout << "-1" << endl;
    return;
  }


  i64 left = x - total_without_rollback;
  i64 ans = (left + max_with_rollback - 1) / max_with_rollback;
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
