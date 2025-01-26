#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 2) {
    cout << "-1" << endl;
    return;
  }

  vector<vector<int>> ans(n, vector<int>(n));
  int idx = 0;
  int sq = n*n;
  for (int i = 1; i <= sq; i += 2, ++idx) {
    int r = idx / n, c = idx % n;
    ans[r][c] = i;
  }
  for (int i = 2; i <= sq; i += 2, ++idx) {
    int r = idx / n, c = idx % n;
    ans[r][c] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
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
