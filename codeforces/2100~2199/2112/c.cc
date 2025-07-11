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

  int max_val = a.back();
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n-1; ++j) {
      int current = a[i] + a[j];
      // current + a[k] > max_val
      auto it1 = lower_bound(a.begin() + j + 1, a.end(), max_val - current + 1);
      int l = it1 - a.begin();
      // current > a[k]
      auto it2 = upper_bound(a.begin() + j + 1, a.end(), current - 1);
      int r = it2 - a.begin();
      int len = max(r-l, 0);
      ans += len;
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
