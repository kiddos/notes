#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  bool found = false;
  array<int, 4> b = {n, m, 0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'R') {
        found = true;
        b[0] = min(b[0], i);
        b[1] = min(b[1], j);
        b[2] = max(b[2], i);
        b[3] = max(b[3], j);
      }
    }
  }

  if (!found) {
    cout << "NO" << endl;
    return;
  }

  if (grid[b[0]][b[1]] == 'R') {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
