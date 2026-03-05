#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  x--;
  y--;
  int n = 8;

  vector<vector<int>> ans(n, vector<int>(n));

  vector<pair<int,int>> delta = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

  auto count_available = [&](int r, int c) -> int {
    int total = 0;
    for (auto [dr, dc] : delta) {
      int r2 = r + dr;
      int c2 = c + dc;
      if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n) {
        continue;
      }
      if (ans[r2][c2]) {
        continue;
      }
      total++;
    }
    return total;
  };

  auto dfs = [&](const auto& self, int r, int c, int step) -> bool {
    if (step == n * n) {
      return true;
    }

    vector<array<int,3>> next_possible;
    for (auto [dr, dc] : delta) {
      int r2 = r + dr;
      int c2 = c + dc;
      if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n) {
        continue;
      }
      if (ans[r2][c2]) {
        continue;
      }
      int count = count_available(r2, c2);
      next_possible.push_back({count, r2, c2});
    }
    sort(next_possible.begin(), next_possible.end());

    for (auto [count, r2, c2] : next_possible) {
      ans[r2][c2] = step+1;
      bool result = self(self, r2, c2, step+1);
      if (result) {
        return true;
      }
      ans[r2][c2] = 0;
    }

    return false;
  };

  ans[y][x] = 1;
  dfs(dfs, y, x, 1);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
