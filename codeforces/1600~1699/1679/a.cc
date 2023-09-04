#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0;
  cin >> x;
  if (x < 4) {
    cout << "-1" << endl;
    return;
  }
  if (x % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  i64 max_bus = 0;
  i64 min_bus = 0;
  i64 y = x;
  while (y % 6 != 0) {
    y -= 4;
    min_bus++;
  }
  min_bus += y / 6;

  y = x;
  while (y % 4 != 0) {
    max_bus++;
    y -= 6;
  }
  max_bus += y / 4;

  cout << min_bus << " " << max_bus << endl;
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
