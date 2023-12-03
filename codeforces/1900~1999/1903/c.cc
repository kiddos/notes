#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> s = a;
  for (int i = n-2; i >= 0; --i) {
    s[i] += s[i+1];
  }

  i64 ans = s[0];
  for (int j = 1; j < n; ++j) {
    if (s[j] > 0) {
      ans += s[j];
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
