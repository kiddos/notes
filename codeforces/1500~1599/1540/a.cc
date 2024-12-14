#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  vector<i64> suffix = d;
  for (int i = n-2; i >= 0; --i) {
    suffix[i] += suffix[i+1];
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i+2 < n) {
      i64 c = n-(i+2);
      ans += d[i] * c - suffix[i+2];
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
