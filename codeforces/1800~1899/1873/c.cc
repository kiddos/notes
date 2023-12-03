#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> grid(10);
  for (int i = 0; i < 10; ++i) cin >> grid[i];

  int ans = 0;
  int l = 0, r = 9;
  for (int i = 0; i < 5; ++i) {
    for (int j = l+1; j <= r; ++j) {
      if (grid[i][j] == 'X') {
        ans += (i+1);
      }
    }
    for (int j = l+1; j <= r; ++j) {
      if (grid[j][r] == 'X') {
        ans += (i+1);
      }
    }
    for (int j = r-1; j >= l; --j) {
      if (grid[r][j] == 'X') {
        ans += (i+1);
      }
    }
    for (int j = r-1; j >= l; --j) {
      if (grid[j][i] == 'X') {
        ans += (i+1);
      }
    }
    l++;
    r--;
    // cout << ans << endl;
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
