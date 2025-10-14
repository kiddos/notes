#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<bool>> visited(n, vector<bool>(n));
  visited[0][0] = true;

  vector<vector<int>> ans(n, vector<int>(n));

  queue<pair<int,int>> q;
  q.push({0, 0});

  int step = 0;
  vector<pair<int,int>> delta = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}};
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();
      ans[r][c] = step;
      for (auto [dr, dc] : delta) {
        int r2 = r + dr, c2 = c + dc;
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n) {
          continue;
        }
        if (visited[r2][c2]) {
          continue;
        }
        visited[r2][c2] = true;
        q.push({r2, c2});
      }
    }
    step++;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
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
