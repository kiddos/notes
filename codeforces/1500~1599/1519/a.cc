#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 r = 0, b = 0, d = 0;
  cin >> r >> b >> d;
  i64 x = min(r, b), y = max(r, b);
  i64 max_y = x * (d+1);
  if (y > max_y) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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
