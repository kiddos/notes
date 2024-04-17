#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [1 2 3 4 5]
// [1 2 3 4 5]
// [1 3 3 4 5]
// [1 4 4 4 5]
// [1 5 5 5 5]

void solve() {
  int n = 0;
  cin >> n;

  vector<pair<int, int>> ops;
  vector<vector<int>> g(n, vector<int>(n));
  for (int k = 0, r = n - 1, c = n - 1; k < n; ++k, --r, --c) {
    ops.emplace_back(1, r+1);
    for (int j = 0; j < n; ++j) {
      g[r][j] = j+1;
    }
    ops.emplace_back(2, c+1);
    for (int i = 0; i < n; ++i) {
      g[i][c] = i+1;
    }
  }

  i64 s = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      s += g[i][j];
    }
  }
  cout << s << " " << ops.size() << endl;
  for (auto& [type, i] : ops) {
    cout << type << " " << i << " ";
    for (int j = 1; j <= n; ++j) cout << j << " ";
    cout << endl;
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
