#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c[i][j];
    }
  }
  vector<int> avenue_min(n);
  for (int i = 0; i < n; ++i) {
    avenue_min[i] = *min_element(c[i].begin(), c[i].end());
  }
  int ans = *max_element(avenue_min.begin(), avenue_min.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
