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

  vector<vector<int>> p(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x = s[i-1][j-1] == '1' ? 1 : 0;
      p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + x;
    }
  }

  auto area = [&](int x1, int y1, int x2, int y2) -> int {
    if (y2 < y1 || x2 < x1) return 0;
    return p[x2+1][y2+1] - p[x2+1][y1] - p[x1][y2+1] + p[x1][y1];
  };

  // suffix sum this
  // xxxxxxx.
  // .......x
  // .......x
  // .......x
  // xxxxxxx.

  int ans = numeric_limits<int>::max();
  constexpr int min_row = 5, min_col = 4;
  constexpr int INF = 100000000;
  for (int r1 = 0; r1 <= n - min_row; ++r1) {
    for (int r2 = r1+min_row-1; r2 < n; ++r2) {
      vector<int> suffix(m, INF);
      for (int c = min_col-1; c < m; ++c) {
        int top = c - area(r1, 0, r1, c-1);
        int bot = c - area(r2, 0, r2, c-1);
        int middle = area(r1+1, 0, r2-1, c-1);
        int right = r2 - r1 - 1 - area(r1+1, c, r2-1, c);
        suffix[c] = middle + top + bot + right;
      }

      // cout << "suffix:" << endl;
      // for (int c = 0; c < m; ++c) {
      //   cout << suffix[c] << " ";
      // }
      // cout << endl;;

      for (int c = m-2; c >= min_col-1; --c) {
        suffix[c] = min(suffix[c], suffix[c+1]);
      }

      for (int c = 0; c <= m-min_col; ++c) {
        int left = r2 - r1 -1 - area(r1+1, c, r2-1, c);
        int suf = suffix[c+min_col-1];

        int top = c + 1 - area(r1, 0, r1, c);
        int bot = c + 1 - area(r2, 0, r2, c);
        int middle = area(r1+1, 0, r2-1, c);
        int prefix = top + bot + middle;

        int area = suf - prefix + left;
        ans = min(ans, area);
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
