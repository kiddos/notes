#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  int ans = 0;
  int m = n / 2;
  for (int i = 0; i < m; ++i) {
    int len = n - 2 * i;
    for (int j = 0; j < len-1; ++j) {
      int c1 = grid[i][i+j] - '0';
      int c2 = grid[i+j][n-i-1] - '0';
      int c3 = grid[n-i-1][n-i-1-j] - '0';
      int c4 = grid[n-i-1-j][i] - '0';
      int sum = c1 + c2 + c3 + c4;
      int op = min(sum, 4 - sum);
      ans += op;
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
