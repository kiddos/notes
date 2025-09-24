#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 MAX_MOVE = 1e9;

i64 move(char d, i64 k) {
  cout << "? " << d << " " << k << endl;
  i64 dist = 0;
  cin >> dist;
  return dist;
}

void answer(i64 x, i64 y) {
  cout << "! " << x << " " << y << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<i64,i64>> points;
  for (int i = 0; i < n; ++i) {
    i64 x = 0, y = 0;
    cin >> x >> y;
    points.emplace_back(x, y);
  }

  move('R', MAX_MOVE);
  move('R', MAX_MOVE);
  move('U', MAX_MOVE);
  i64 a = move('U', MAX_MOVE);
  // a = ((x + 2z) - max xi) + ((y + 2z) - max yi)
  //   = (x + y - max (xi + yi) + 4z)

  move('D', MAX_MOVE);
  move('D', MAX_MOVE);
  move('D', MAX_MOVE);
  i64 b = move('D', MAX_MOVE);
  // b = ((x + 2z) - max xi) + (min yi - (y - 2z))
  //   = (x - y + 4z + min (yi - xi))
  //
  // => a + b = 2 * x + 8z - max_val + min_val
  // => 2 * x = a + b - 8z + max_val - min_val
  // => x = (a + b - 8z + max_val - min_val) / 2
  //
  // => a - b = 2 * y - max_val - min_val
  // => y = (a - b + max_val + min_val) / 2

  i64 max_val = numeric_limits<i64>::min();
  i64 min_val = numeric_limits<i64>::max();
  for (auto [x, y] : points) {
    max_val = max(max_val, x + y);
    min_val = min(min_val, y - x);
  }

  // cerr << "a=" << a << ",b=" << b<< endl;

  i64 x = (a + b - 8LL * MAX_MOVE + max_val - min_val) / 2;
  i64 y = (a - b + max_val + min_val) / 2;
  answer(x, y);
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
