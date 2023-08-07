#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    int start = i % 4 == 0 || i % 4 == 3 ? 1 : 0;
    for (int j = 0; j < m; ++j) {
      int x = j % 4 == 0 || j % 4 == 3 ? 0 : 1;
      grid[i][j] = x ^ start;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << grid[i][j] << " ";
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
