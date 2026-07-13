#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> delta = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (isdigit(s[i][j]) || s[i][j] == '.') {
        int bomb = 0;
        for (vector<int>& d : delta) {
          int r = i+d[0], c = j + d[1];
          if (r < 0 || r >= n || c < 0 || c >= m) {
            continue;
          }
          if (s[r][c] == '*') {
            bomb++;
          }
        }

        if (isdigit(s[i][j])) {
          if (bomb != s[i][j] - '0') {
            cout << "NO" << endl;
            return;
          }
        } else if (s[i][j] == '.') {
          if (bomb > 0) {
            cout << "NO" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
