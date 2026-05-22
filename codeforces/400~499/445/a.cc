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
  vector<int> cells(2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int p = (i+j) % 2;
      if (s[i][j] == 'B') {
        cells[p] |= 1;
      } else if (s[i][j] == 'W') {
        cells[p] |= 2;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '-') {
        continue;
      }

      if (s[i][j] == '.') {
        int p = (i+j) % 2;
        if (cells[p] == 1) {
          s[i][j] = 'B';
        } else if (cells[p] == 2) {
          s[i][j] = 'W';
        } else {
          if (cells[1-p] == 1) {
            s[i][j] = 'W';
            cells[p] = 2;
          } else if (cells[1-p] == 2) {
            s[i][j] = 'B';
            cells[p] = 1;
          } else {
            s[i][j] = 'B';
            cells[p] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << s[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
