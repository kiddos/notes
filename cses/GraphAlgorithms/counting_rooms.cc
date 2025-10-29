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

  vector<vector<int>> ids(n, vector<int>(m));
  auto dfs = [&](const auto& self, int r, int c, int id) {
    if (r < 0 || r >= n || c < 0 || c >= m || s[r][c] == '#') {
      return;
    }
    if (ids[r][c]) {
      return;
    }
    ids[r][c] = id;
    self(self, r-1, c, id);
    self(self, r+1, c, id);
    self(self, r, c-1, id);
    self(self, r, c+1, id);
  };

  int id = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!ids[i][j] && s[i][j] == '.') {
        dfs(dfs, i, j, ++id);
      }
    }
  }
  cout << id << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
