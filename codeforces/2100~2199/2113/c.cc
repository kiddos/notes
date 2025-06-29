#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<vector<int>> p(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int g = s[i-1][j-1] == 'g' ? 1 : 0;
      p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + g;
    }
  }

  auto detonate = [&](int r, int c) -> int {
    int len = k-1;
    int x0 = max(r - len, 0), y0 = max(c - len, 0);
    int x1 = min(r + len, n-1), y1 = min(c + len, m-1);
    int sum = p[x1+1][y1+1] - p[x0][y1+1] - p[x1+1][y0] + p[x0][y0];
    return sum;
  };

  int total = p[n][m];
  int ans = 0;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (s[r][c] == '.') {
        int remove = detonate(r, c);
        ans = max(ans, total - remove);
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
