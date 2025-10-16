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

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char top = i > 0 ? grid[i-1][j] : ' ';
      char left = j > 0 ? grid[i][j-1] : ' ';
      bool found = false;
      for (char ch = 'A'; ch <= 'D'; ++ch) {
        if (ch == top || ch == left || ch == grid[i][j]) {
          continue;
        }
        grid[i][j] = ch;
        found = true;
        break;
      }
      if (!found) {
        cout << "NO SOLUTION" << endl;
      }
    }
  }

  for (string& row : grid) {
    cout << row << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
