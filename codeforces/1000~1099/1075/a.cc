#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, x = 0, y = 0;
  cin >> n >> x >> y;

  auto compute_move = [&](i64 r, i64 c) -> i64 {
    i64 dx = abs(r - x);
    i64 dy = abs(c - y);
    i64 diag = min(dx, dy);
    dx -= diag;
    dy -= diag;
    return diag + dx + dy;
  };

  i64 white_move = compute_move(1, 1);
  i64 black_move = compute_move(n, n);
  if (white_move <= black_move) {
    cout << "White" << endl;
  } else {
    cout << "Black" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
