#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> s(4);
  for (int i = 0; i < 4; ++i) {
    cin >> s[i];
  }

  auto in_range = [&](int r, int c) -> bool {
    return r >= 0 && r < 4 && c >= 0 && c < 4;
  };

  vector<vector<int>> delta = {{-1, 0}, {-1, -1}, {0, -1}, {-1, 1}};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (s[i][j] == '.') {
        for (vector<int>& d : delta) {
          int r2 = i + d[0], c2 = j + d[1];
          int r3 = i - d[0], c3 = j - d[1];
          if (in_range(r2, c2) && in_range(r3, c3) && s[r2][c2] == 'x' && s[r3][c3] == 'x') {
            cout << "YES" << endl;
            return;
          }

          r2 = i + d[0], c2 = j + d[1];
          r3 = i + d[0] * 2, c3 = j + d[1] * 2;
          if (in_range(r2, c2) && in_range(r3, c3) && s[r2][c2] == 'x' && s[r3][c3] == 'x') {
            cout << "YES" << endl;
            return;
          }

          r2 = i - d[0], c2 = j - d[1];
          r3 = i - d[0] * 2, c3 = j - d[1] * 2;
          if (in_range(r2, c2) && in_range(r3, c3) && s[r2][c2] == 'x' && s[r3][c3] == 'x') {
            cout << "YES" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
