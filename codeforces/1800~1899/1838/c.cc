#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  int k = 1;
  for (int i = 1; i < n; i += 2) {
    for (int j = 0; j < m; ++j) {
      grid[i][j] = k++;
    }
  }
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; ++j) {
      grid[i][j] = k++;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
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
