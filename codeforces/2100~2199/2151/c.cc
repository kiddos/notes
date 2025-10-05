#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = 2 * n;
  vector<i64> a(m+1);
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
  }

  vector<i64> ans(n);
  i64 left = 0;
  for (int i = 1; i <= n; ++i)  {
    left += a[i];
  }
  i64 right = 0;
  for (int i = n+1; i <= m; ++i){
    right += a[i];
  }

  ans[n-1] = right - left;
  i64 current = 0;
  for (int k = n-2, l = n, r = n+1; k >= 0; --k, --l, ++r) {
    current = a[l] - a[r] - current;
    right -= a[r];
    left -= a[l];
    ans[k] = current + right - left;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
