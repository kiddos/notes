#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<string> grid(8);
  string s;
  for (int i = 0; i < 8; ++i) cin >> grid[i];

  auto row_same = [&](int i) -> bool {
    char c = grid[i][0];
    if (c != 'R') return false;

    for (int j = 1; j < 8; ++j) {
      if (grid[i][j] != c) return false;
    }
    return true;
  };

  auto col_same = [&](int j) -> bool {
    char c = grid[0][j];
    if (c != 'B') return false;

    for (int i = 1; i < 8; ++i) {
      if (grid[i][j] != c) return false;
    }
    return true;
  };

  for (int i = 0; i < 8; ++i) {
    if (row_same(i)) {
      cout << "R" << endl;
      return;
    }
  }

  for (int j = 0; j < 8; ++j) {
    if (col_same(j)) {
      cout << "B" << endl;
      return;
    }
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
