#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> grid[i][j];
  }

  queue<pair<int,int>> q;
  q.push({0, 0});
  int step = 0;
  vector<vector<int>> delta = {{0, 0}, {1, 1}, {2, 0}};
  vector<vector<bool>> visited(n, vector<bool>(m));
  visited[0][0] = true;

  int ans = numeric_limits<int>::max();
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();

      
      if (c == m-1) {
        int target = n-1 + step;
        int rest = r - target;
        if (rest < 0) {
          rest = ((rest % n) + n) % n;
        }
        ans = min(ans, rest + step);
      }

      for (vector<int>& d : delta) {
        int r2 = (r + d[0]) % n, c2 = c + d[1];
        if (c2 < 0 || c2 >= m) continue;
        if (grid[r2][c2]) continue;
        if (d[0] == 2 && grid[(r+1) % n][c2]) continue;
        if (visited[r2][c2]) continue;
        visited[r2][c2] = true;

        q.push({r2, c2});
      }
    }
    step++;
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
