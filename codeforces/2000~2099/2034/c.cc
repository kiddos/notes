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

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  string next_char = "ULDR";
  queue<pair<int,int>> q;
  vector<vector<bool>> visited(n, vector<bool>(m));
  auto start = [&](int i, int j) {
    q.emplace(i, j);
    visited[i][j] = true;
  };
  for (int j = 0; j < m; ++j) {
    if (s[0][j] == 'U') {
      start(0, j);
    }
    if (s[n-1][j] == 'D') {
      start(n-1, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i][0] == 'L') {
      start(i, 0);
    }
    if (s[i][m-1] == 'R') {
      start(i, m-1);
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        vector<int>& d = delta[k];
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
        if (visited[r2][c2]) continue;
        if (s[r2][c2] == next_char[k]) {
          visited[r2][c2] = true;
          q.emplace(r2, c2);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j]) {
        if (s[i][j] == '?') {
          // find a neighbor not visited
          bool found = false;
          for (vector<int>& d : delta) {
            int r2 = i + d[0], c2 = j + d[1];
            if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && !visited[r2][c2]) {
              found = true;
              break;
            }
          }
          if (found) {
            ans++;
          }
        } else {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
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
