#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string s;
bool visited[9][9];
vector<array<int, 2>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int backtrack(int i, int r, int c) {
  // optimization
  // if we can only go left or right
  // this means if we choose to go right cell,
  // we would at most reach the left cell at the end
  // since there is no way to go back through this cell again
  // same thing for top and bottom
  if (visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1]) {
    return 0;
  }
  if (!visited[r-1][c] && !visited[r+1][c] && visited[r][c-1] && visited[r][c+1]) {
    return 0;
  }

  if (r == 7 && c == 1) {
    if (i == (int)s.length()) {
      return 1;
    }
    return 0;
  }
  if (i == (int)s.length()) {
    return 0;
  }

  visited[r][c] = true;

  i64 ans = 0;
  if (s[i] == '?') {
    for (array<int, 2>& d : delta) {
      int r2 = r + d[0], c2 = c + d[1];
      if (!visited[r2][c2]) {
        ans += backtrack(i+1, r2, c2);
      }
    }
  } else {
    if (s[i] == 'R') {
      if (!visited[r][c+1]) {
        ans += backtrack(i+1, r, c+1);
      }
    } else if (s[i] == 'L') {
      if (!visited[r][c-1]) {
        ans += backtrack(i+1, r, c-1);
      }
    } else if (s[i] == 'U') {
      if (!visited[r-1][c]) {
        ans += backtrack(i+1, r-1, c);
      }
    } else if (s[i] == 'D') {
      if (!visited[r+1][c]) {
        ans += backtrack(i+1, r+1, c);
      }
    }
  }
  visited[r][c] = false;
  return ans;
}

void precompute() {
  for (int i = 0; i < 9; ++i) {
    visited[i][0] = visited[i][8] = true;
    visited[0][i] = visited[8][i] = true;
  }
}

void solve() {
  cin >> s;
  int ans = backtrack(0, 1, 1);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();
  solve();
  return 0;
}
