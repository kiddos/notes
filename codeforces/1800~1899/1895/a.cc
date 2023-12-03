#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0, k = 0;
  cin >> x >> y >> k;

  if (y < x) {
    cout << x << endl;
  } else {
    int z = min(y, x + k);
    cout << (y - z) * 2 + z << endl;
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
