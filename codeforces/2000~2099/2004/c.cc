#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  for (int i = 1; i < n; i += 2) {
    int to_add = min(a[i-1] - a[i], k);
    a[i] += to_add;
    k -= to_add;
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      ans += a[i];
    } else {
      ans -= a[i];
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
