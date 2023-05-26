#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  int l = 1, r = n * 2;
  vector<vector<int>> grid(2, vector<int>(n));
  grid[0][0] = r--;
  if (n % 2 == 1) {
    grid[1][n-1] = l++;
  } else {
    grid[1][n-1] = r--;
  }
  for (int i = 1; i < n; ++i) {
    if (i % 2 == 1) {
      grid[0][i] = l++;
      grid[1][i-1] = l++;
    } else {
      grid[1][i-1] = r--;
      grid[0][i] = r--;
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) cout << grid[i][j] << " ";
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
