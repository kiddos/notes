#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<string> field(n);
  for (int i = 0; i < n; ++i) cin >> field[i];

  vector<vector<int>> p(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch = field[i-1][j-1];
      int x = ch == '#' ? 1 : 0;
      p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + x;
    }
  }

  auto square_sum = [&](int r1, int c1, int r2, int c2) -> int {
    if (r1 > r2) swap(r1, r2);
    if (c1 > c2) swap(c1, c2);
    r1 = max(r1, 0);
    r2 = min(r2, n-1);
    c1 = max(c1, 0);
    c2 = min(c2, m-1);
    if (r1 > r2 || c1 > c2) return 0;
    // cout << "sum(" << r1 << ", " << c1 << ", " << r2 << ", " << c2 << ") = "
    //   << p[r2+1][c2+1] - p[r2+1][c1] - p[r1][c2+1] + p[r1][c1] << endl;
    return p[r2+1][c2+1] - p[r2+1][c1] - p[r1][c2+1] + p[r1][c1];
  };

  vector<vector<int>> delta = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
  function<int(int,int,int,int)> shotgun = [&](int r, int c, int s, int d) -> int {
    if (s <= 0) {
      return 0;
    }
    if (r < 0 || c < 0 || r >= n || c >= m) {
      return 0;
    }

    // cout << r << "," << c << ",s=" << s << " ";
    if (s == 1) {
      return square_sum(r, c, r, c);
    }

    int size = (s + 1) / 2;
    s = s / 2;
    vector<int>& diff = delta[d];
    return square_sum(r, c, r + (size-1) * diff[0], c + (size-1) * diff[1]) +
      shotgun(r + size * diff[0], c, s, d) +
      shotgun(r, c + size * diff[1], s, d);
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int d = 0; d < 4; ++d) {
        ans = max(ans, shotgun(i, j, k+1, d));
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
