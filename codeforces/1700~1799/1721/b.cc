#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0, sx = 0, sy = 0, d = 0;
  cin >> n >> m >> sx >> sy >> d;

  auto in_range = [&](int x, int y) {
    int dist = abs(x - sx) + abs(y - sy);
    return dist <= d;
  };

  bool path1 = true;
  for (int x = 1; x <= n && path1; ++x) {
    if (in_range(x, 1)) {
      path1 = false;
    }
  }
  for (int y = 1; y <= m && path1; ++y) {
    if (in_range(n, y)) {
      path1 = false;
    }
  }

  bool path2 = true;
  for (int y = 1; y <= m && path2; ++y) {
    if (in_range(1, y)) {
      path2 = false;
    }
  }
  for (int x = 1; x <= n && path2; ++x) {
    if (in_range(x, m)) {
      path2 = false;
    }
  }

  if (path1 || path2) {
    cout << m+n-2 << endl;
  } else {
    cout << "-1" << endl;
  }
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
