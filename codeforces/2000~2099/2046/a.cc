#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  i64 ans = 0;
  for (int j = 0; j < n; ++j) {
    ans += max(a[0][j], a[1][j]);
  }
  int max_min = numeric_limits<int>::min();
  for (int j = 0; j < n; ++j) {
    int minval = min(a[0][j], a[1][j]);
    max_min = max(max_min, minval);
  }
  ans += max_min;
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
