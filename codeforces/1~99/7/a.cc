#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> s(8);
  for (int i = 0; i < 8; ++i) {
    cin >> s[i];
  }

  vector<int> row_blacks(8), col_blacks(8);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (s[i][j] == 'B') {
        row_blacks[i]++;
        col_blacks[j]++;
      }
    }
  }

  int rows = 0, cols = 0;
  for (int i = 0; i < 8; ++i) {
    if (row_blacks[i] == 8) {
      rows++;
    }
    if (col_blacks[i] == 8) {
      cols++;
    }
  }
  if (rows == 8 || cols == 8) {
    cout << "8" << endl;
    return;
  }
  int ans = rows + cols;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
