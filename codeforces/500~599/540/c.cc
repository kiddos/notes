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
  int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
  cin >> r1 >> c1 >> r2 >> c2;
  r1--;
  c1--;
  r2--;
  c2--;

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  if (r1 == r2 && c1 == c2) {
    bool possible = false;
    for (vector<int>& d : delta) {
      int r3 = r1 + d[0], c3 = c1 + d[1];
      if (r3 < 0 || r3 >= n || c3 < 0 || c3 >= m) {
        continue;
      }
      if (s[r3][c3] == '.') {
        possible = true;
        break;
      }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return;
  }

  auto reachable = [&]() -> bool {
    queue<pair<int,int>> q;
    q.push({r1, c1});
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[r1][c1] = true;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        auto [r, c] = q.front();
        q.pop();

        for (vector<int>& d : delta) {
          int r3 = r + d[0], c3 = c + d[1];
          if (r3 < 0 || r3 >= n || c3 < 0 || c3 >= m) {
            continue;
          }
          if (r3 == r2 && c3 == c2) {
            return true;
          }
          if (s[r3][c3] == 'X') {
            continue;
          }
          if (visited[r3][c3]) {
            continue;
          }
          visited[r3][c3] = true;
          q.push({r3, c3});
        }
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     cout << visited[i][j];
    //   }
    //   cout << endl;
    // }
    return false;
  };

  if (!reachable()) {
    cout << "NO" << endl;
    return;
  }

  if (s[r2][c2] == 'X') {
    cout << "YES" << endl;
    return;
  }

  int intact_count = 0;
  for (vector<int>& d : delta) {
    int r3 = r2 + d[0], c3 = c2 + d[1];
    if (r3 < 0 || r3 >= n || c3 < 0 || c3 >= m) {
      continue;
    }
    if (s[r3][c3] == '.') {
      intact_count++;
    }
  }

  int dist = abs(r1 - r2) + abs(c1 - c2);
  if (dist == 1) {
    if (intact_count >= 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (intact_count >= 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
