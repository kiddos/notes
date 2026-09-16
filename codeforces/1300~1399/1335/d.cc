#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> grid(9);
  for (int i = 0; i < 9; ++i) {
    cin >> grid[i];
  }

  vector<int> count(9, 1);
  for (int x = 0; x < 3; ++x) {
    vector<int> col(3), row(3);
    for (int y = 0; y < 3; ++y) {
      for (int r = y * 3; r < (y+1) * 3; ++r) {
        for (int c = x * 3; c < (x+1) * 3; ++c) {
          if (grid[r][c] == '1') {
            col[y] = c;
            row[y] = r;
          }
        }
      }
    }

    for (int y = 0; y < 3; ++y) {
      int c2 = col[(y+1)%3];
      int r2 = row[y];
      grid[r2][c2] = '1';
    }
  }

  for (int i = 0; i < 9; ++i) {
    cout << grid[i] << endl;
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
