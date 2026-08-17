#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<i64, int> require;
  for (int i = 0; i < n; ++i) {
    if (a[i] % k != 0) {
      i64 y = a[i] % k;
      require[k-y]++;
    }
  }

  i64 ans = 0;
  for (auto [i, r] : require) {
    i64 step = (r-1) * k + i + 1;
    ans = max(ans, step);
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
