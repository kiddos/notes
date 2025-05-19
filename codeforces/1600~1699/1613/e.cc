#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  queue<pair<int,int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'L') {
        q.push({i, j});
        break;
      }
    }
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  auto one_way = [&](int r, int c) -> bool {
    int dots = 0;
    for (vector<int>& d : delta) {
      int r2 = r + d[0], c2 = c + d[1];
      if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) {
        continue;
      }
      if (grid[r2][c2] == '.') {
        dots++;
      }
    }
    return dots <= 1;
  };

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();

      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) {
          continue;
        }
        if (grid[r2][c2] != '.') {
          continue;
        }
        
        if (one_way(r2, c2)) {
          grid[r2][c2] = '+';
          q.push({r2, c2});
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << grid[i] << '\n';
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
