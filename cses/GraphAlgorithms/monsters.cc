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
  pair<int,int> start;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'A') {
        start = {i, j};
      }
    }
  }

  queue<pair<int,int>> q;
  vector<vector<int>> monster(n, vector<int>(m, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'M') {
        monster[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  string dir = "DRUL";
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();

      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m || s[r2][c2] == '#') {
          continue;
        }
        if (monster[r2][c2] >= 0) {
          continue;
        }
        monster[r2][c2] = monster[r][c] + 1;
        q.push({r2, c2});
      }
    }
  }

  q.push(start);
  int t = 1;
  vector<vector<bool>> visited(n, vector<bool>(m));
  visited[start.first][start.second] = true;
  vector<vector<array<int,3>>> prev(n, vector<array<int,3>>(m));
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();

      for (int d = 0; d < 4; ++d) {
        int r2 = r + delta[d][0], c2 = c + delta[d][1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m || s[r2][c2] == '#') {
          continue;
        }
        if (monster[r2][c2] >= 0 && t >= monster[r2][c2]) {
          continue;
        }
        if (visited[r2][c2]) {
          continue;
        }
        visited[r2][c2] = true;
        prev[r2][c2] = {r, c, d};

        q.push({r2, c2});
      }
    }
    t++;
  }

  pair<int,int> end = {-1, -1};
  for (int i = 0; i < n; ++i) {
    if (visited[i][0]) {
      end = {i, 0};
      break;
    }
    if (visited[i][m-1]) {
      end = {i, m-1};
      break;
    }
  }
  for (int j = 0; j < m; ++j) {
    if (visited[0][j]) {
      end = {0, j};
      break;
    }
    if (visited[n-1][j]) {
      end = {n-1, j};
      break;
    }
  }

  if (end.first == -1 && end.second == -1) {
    cout << "NO" << endl;
    return;
  }

  auto current = end;
  string ans;
  while (current.first != start.first || current.second != start.second) {
    auto [r0, c0, d] = prev[current.first][current.second];
    current = {r0, c0};
    ans.push_back(dir[d]);
  }
  reverse(ans.begin(), ans.end());

  cout << "YES" << endl;
  cout << ans.size() << endl;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
