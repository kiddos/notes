#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<vector<int>> grid(3, vector<int>(3));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<int>> total(3, vector<int>(3, 1));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      total[i][j] += grid[i][j];
      for (vector<int>& d : delta) {
        int r = i + d[0], c = j + d[1];
        if (r >= 0 && r < 3 && c >= 0 && c < 3) {
          total[r][c] += grid[i][j];
        }
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << total[i][j]%2;
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
