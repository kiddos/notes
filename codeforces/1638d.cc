#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> Op;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> canvas(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> canvas[i][j];
    }
  }

  queue<Op> q;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-1; ++j) {
      if (canvas[i][j] == canvas[i][j+1] &&
          canvas[i][j] == canvas[i+1][j] &&
          canvas[i][j] == canvas[i+1][j+1]) {
        q.push({i, j, canvas[i][j]});
        canvas[i][j] = canvas[i][j+1] = canvas[i+1][j] = canvas[i+1][j+1] = -1;
      }
    }
  }

  vector<int> dx = {-1, 0, 1};
  vector<int> dy = {-1, 0, 1};
  vector<Op> ans;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto op = q.front();
      q.pop();
      ans.push_back(op);

      for (int d1 : dy) {
        for (int d2 : dx) {
          int r = op[0] + d1, c = op[1] + d2;
          if (r == op[0] && c == op[1]) continue;
          if (r < 0 || r+1 >= n || c < 0 || c+1 >= m) continue;
          int color = canvas[r][c] > 0 ? canvas[r][c] :
              canvas[r+1][c] > 0 ? canvas[r+1][c] :
              canvas[r][c+1] > 0 ? canvas[r][c+1] :
              canvas[r+1][c+1] > 0 ? canvas[r+1][c+1] : -1;
          if (color == -1) continue;
          if ((canvas[r][c] != -1 && canvas[r][c] != color) ||
              (canvas[r+1][c] != -1 && canvas[r+1][c] != color) ||
              (canvas[r][c+1] != -1 && canvas[r][c+1] != color) ||
              (canvas[r+1][c+1] != -1 && canvas[r+1][c+1] != color)) continue;
          canvas[r][c] = canvas[r+1][c] = canvas[r][c+1] = canvas[r+1][c+1] = -1;
          q.push({r, c, color});
        }
      }
    }
  }

  bool done = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // cout << canvas[i][j] << " ";
      if (canvas[i][j] != -1) {
        done = false;
      }
    }
      // cout << endl;
  }

  if (done) {
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& o : ans) {
      cout << o[0]+1 << ' ' << o[1]+1 << ' ' << o[2] << '\n';
    }
    cout << flush;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
