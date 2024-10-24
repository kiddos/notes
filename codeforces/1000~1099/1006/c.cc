#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 pref = 0, suf = 0;
  i64 ans = 0;
  for (int l = 0, r = n-1; l < n; ++l) {
    pref += a[l];
    while (r > l && suf < pref) {
      suf += a[r--];
    }
    if (suf == pref && l <= r) {
      ans = max(ans, pref);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
