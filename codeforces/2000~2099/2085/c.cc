#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0;
  cin >> x >> y;
  if (x == y) {
    cout << "-1" << endl;
    return;
  }

  i64 max_val = max(x, y);
  i64 b = 0;
  while ((1LL<<b) <= max_val) {
    b++;
  }
  i64 k = (1LL<<b) - max_val;
  cout << k << endl;

  assert((x + k + y + k) == ((x + k) ^ (y + k)));
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
