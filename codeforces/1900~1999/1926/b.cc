#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  vector<int> row(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      row[i] += grid[i][j] == '1';
    }
  }

  for (int i = 1; i < n; ++i) {
    if (row[i] > 0 && row[i-1] > 0) {
      if (row[i] == row[i-1]) {
        cout << "SQUARE" << endl;
      } else {
        cout << "TRIANGLE" << endl;
      }
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}