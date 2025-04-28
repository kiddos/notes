#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<i64> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = max(l[i], r[i]);
    b[i] = min(l[i], r[i]);
  }
  i64 ans = accumulate(a.begin(), a.end(), 0LL);
  sort(b.rbegin(), b.rend());
  for (int i = 0; i < k; ++i) {
    if (i == k-1) {
      ans++;
    } else {
      ans += b[i];
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
