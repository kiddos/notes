#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<string> grid(8);
  for (int i = 0; i < 8; ++i) {
    cin >> grid[i];
  }

  string ans;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (grid[i][j] != '.') {
        for (int k = i; k < 8 && grid[k][j] != '.'; ++k) {
          ans.push_back(grid[k][j]);
        }
        cout << ans << endl;
        return;
      }
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
