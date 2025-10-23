#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 max_val = a.back();
  i64 rest = 0;
  for (int i = 0; i < n-1; ++i) {
    rest += a[i];
  }
  i64 ans = max_val * (n-2) - rest;
  if (ans < 0) {
    ans %= (n-1);
    if (ans < 0) {
      ans += (n-1);
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
