#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<unordered_set<char>> cells(2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] != '.') {
        int c = (i+j) % 2;
        cells[c].insert(grid[i][j]);
      }
    }
  }

  vector<char> chars = {'W', 'R'};
  if (cells[0].size() > 1 || cells[1].size() > 1) {
    cout << "NO" << endl;
    return;
  } else if (cells[0].size() == 1 && cells[1].size() == 1) {
    chars[0] = *cells[0].begin(), chars[1] = *cells[1].begin();
    if (chars[0] == chars[1]) {
      cout << "NO" << endl;
      return;
    }
  } else if (cells[0].size() == 1) {
    chars[0] = *cells[0].begin();
    chars[1] = chars[0] == 'W' ? 'R' : 'W';
  } else if (cells[1].size() == 1) {
    chars[1] = *cells[1].begin();
    chars[0] = chars[1] == 'W' ? 'R' : 'W';
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') {
        int c = (i+j) % 2;
        grid[i][j] = chars[c];
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << grid[i] << '\n';
  }
  cout << flush;
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
