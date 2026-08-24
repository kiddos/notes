#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, w = 0, k = 0;
  cin >> h >> w >> k;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }

  vector<bool> row_has_bomb(h);
  vector<bool> col_has_bomb(w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') {
        row_has_bomb[i] = true;
        col_has_bomb[j] = true;
      }
    }
  }

  queue<pair<int,int>> q;
  vector<vector<int>> dist(h, vector<int>(w, -1));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!row_has_bomb[i] && !col_has_bomb[j]) {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();
      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= h || c2 < 0 || c2 >= w) {
          continue;
        }
        if (dist[r2][c2] >= 0) {
          continue;
        }
        if (s[r2][c2] == '#') {
          continue;
        }
        dist[r2][c2] = dist[r][c]+1;
        q.push({r2, c2});
      }
    }
  }

  // for (int i = 0; i < h; ++i) {
  //   for (int j = 0; j < w; ++j) {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (dist[i][j] >= 0 && dist[i][j] <= k) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
