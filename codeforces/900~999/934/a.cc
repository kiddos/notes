#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  i64 ans1 = numeric_limits<i64>::min();
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m; ++j) {
      ans1 = max(ans1, a[i] * b[j]);
    }
  }
  i64 ans2 = numeric_limits<i64>::min();
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans2 = max(ans2, a[i] * b[j]);
    }
  }

  i64 ans = min(ans1, ans2);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
