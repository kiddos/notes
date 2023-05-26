#include <bits/stdc++.h>

using namespace std;


void solve() {
  int n = 0;
  cin >> n;
  int r1 = 0, c1 = 0, r2 = 0, c2 = 0, r3 = 0, c3 = 0;
  cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
  int x = 0, y = 0;
  cin >> x >> y;

  auto is_corner = [&](int r, int c) {
    return (r == 1 && c == 1) || (r == 1 && c == n) || (r == n && c == 1) || (r == n && c == n);
  };

  int r = 0;
  if (r1 == r2) {
    r = r3;
  } else if (r2 == r3) {
    r = r1;
  } else if (r1 == r3) {
    r = r2;
  }

  int c = 0;
  if (c1 == c2) {
    c = c3;
  } else if (c1 == c3) {
    c = c2;
  } else if (c2 == c3) {
    c = c1;
  }

  bool corner = is_corner(r1, c1) || is_corner(r2, c2) || is_corner(r3, c3);
  if (r == 2 && c == 2 && corner) {
    if (x == 1 || y == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (r == 2 && c == n - 1 && corner) {
    if (x == 1 || y == n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (r == n-1 && c == 2 && corner) {
    if (x == n || y == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (r == n-1 && c == n-1 && corner) {
    if (x == n || y == n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    int dx = abs(x - r);
    int dy = abs(y - c);
    if (dx % 2 == 0 && dy % 2 == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
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
