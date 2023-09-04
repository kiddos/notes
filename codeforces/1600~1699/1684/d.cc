#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i] + i + 1;
  }
  sort(b.rbegin(), b.rend());

  i64 ans = accumulate(a.begin(), a.end(), 0LL);
  for (int i = 0; i < k; ++i) {
    ans -= b[i];
    ans += n;
    ans -= i;
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
