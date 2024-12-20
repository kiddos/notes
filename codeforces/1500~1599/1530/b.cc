#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, w = 0;
  cin >> h >> w;
  vector<string> ans(h, string(w, '0'));

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  auto can_put = [&](int r, int c) -> bool {
    for (vector<int>& d : delta) {
      int r2 = r + d[0], c2 = c + d[1];
      if (r2 < 0 || r2 >= h || c < 0 || c >= w) continue;
      if (ans[r2][c2] == '1') return false;
    }
    return true;
  };

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i == 0 || j == 0 || i == h-1 || j == w -1) {
        if (can_put(i, j)) {
          ans[i][j] = '1';
        }
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    cout << ans[i] << '\n';
  }
  cout << endl;
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
