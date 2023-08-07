#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  pair<int,int> coord = {0, 0};
  int x = numeric_limits<int>::min();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];

      if (a[i][j] > x) {
        x = a[i][j];
        coord = {i, j};
      }
    }
  }

  i64 i = coord.first;
  i64 j = coord.second;
  i64 ans = max({
    (i+1) * (j+1),
    (i+1) * (m-j),
    (n-i) * (j+1),
    (n-i) * (m-j)
  });

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
