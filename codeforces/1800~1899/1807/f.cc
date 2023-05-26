#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
  string d;
  cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;

  vector<vector<int>> delta = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  vector<vector<vector<bool>>> visited(n+1, vector<vector<bool>>(m+1, vector<bool>(4)));

  unordered_map<string, int> dir = {{"DR", 0}, {"DL", 1}, {"UR", 2}, {"UL", 3}};

  function<int(int,int,int)> dfs = [&](int r, int c, int d) {
    // cout << r << ", " << c << ", " << d << endl;
    if (visited[r][c][d]) return -1;
    if (r == i2 && c == j2) return 0;
    visited[r][c][d] = true;

    int d2 = d;
    int r2 = r + delta[d][0], c2 = c + delta[d][1];
    int b = 0;
    if (r2 < 1 || r2 > n) {
      d2 = (d2 + 2) % 4;
      r2 = r + delta[d2][0];
      b++;
    }
    if (c2 < 1 || c2 > m) {
      if (d2 % 2 == 0) d2++;
      else d2--;
      c2 = c + delta[d2][1];
      if (!b) b++;
    }
    int ans = dfs(r2, c2, d2);
    if (ans < 0) return ans;
    return ans + b;
  };

  int ans = dfs(i1, j1, dir[d]);
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
