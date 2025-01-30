#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  int sx = x[0], sy = y[0];
  int min_x = sx, max_x = sx + m;
  int min_y = sy, max_y = sy + m;
  for (int i = 1; i < n; ++i) {
    sx += x[i];
    sy += y[i];
    min_x = min(min_x, sx);
    min_y = min(min_y, sy);
    max_x = max(max_x, sx + m);
    max_y = max(max_y, sy + m);
  }
  int width = max_x - min_x;
  int height = max_y - min_y;
  int ans = (width + height) * 2;
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
