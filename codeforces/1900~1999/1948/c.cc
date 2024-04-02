#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> grid(2);
  cin >> grid[0] >> grid[1];

  queue<pair<int,int>> q;
  q.push({0, 0});
  vector<vector<bool>> visited(2, vector<bool>(n));
  visited[0][0] = true;

  vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();
      
      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= 2 || c2 < 0 || c2 >= n) continue;
        if (grid[r2][c2] == '<') {
          c2--;
        } else if (grid[r2][c2] == '>') {
          c2++;
        }
        if (visited[r2][c2]) continue;

        visited[r2][c2] = true;
        q.push({r2, c2});
      }
    }
  }

  if (visited[1][n-1]) {
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
