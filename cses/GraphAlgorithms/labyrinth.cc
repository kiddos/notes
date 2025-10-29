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
  pair<int,int> start, end;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'A') {
        start = {i, j};
      } else if (s[i][j] == 'B') {
        end = {i, j};
      }
    }
  }

  string dir = "DRUL";
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<bool>> visited(n, vector<bool>(m));
  vector<vector<array<int,3>>> prev(n, vector<array<int,3>>(m));
  queue<pair<int,int>> q;
  q.push(start);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();

      for (int d = 0; d < 4; ++d) {
        int r2 = r + delta[d][0], c2 = c + delta[d][1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m || s[r2][c2] == '#') {
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
  }

  if (!visited[end.first][end.second]) {
    cout << "NO" << endl;
    return;
  }

  string ans;
  auto p = end;
  while (p.first != start.first || p.second != start.second) {
    auto [r0, c0, d] = prev[p.first][p.second];
    ans.push_back(dir[d]);
    p = {r0, c0};
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
