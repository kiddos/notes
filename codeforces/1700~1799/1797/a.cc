#include <bits/stdc++.h>

using namespace std;

int block(int x, int y, int n, int m) {
  if (x == 1 && y == 1) return 2;
  if (x == 1 && y == m) return 2;
  if (x == n && y == 1) return 2;
  if (x == n && y == m) return 2;
  if (x == 1 || x == n) return 3;
  if (y == 1 || y == m) return 3;
  return 4;
}

void solve() {
  int n = 0, m = 0;
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> n >> m;
  cin >> x1 >> y1 >> x2 >> y2;
  int ans = min(block(x1, y1, n, m), block(x2, y2, n, m));
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
