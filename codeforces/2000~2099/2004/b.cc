#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  int L = 0, R = 0;
  cin >> l >> r >> L >> R;
  int x = max(l, L);
  int y = min(r, R);
  if (x <= y) {
    int intersect = y - x + 1;
    int ans = intersect + 1;
    if (x == min(l, L)) ans--;
    if (y == max(r, R)) ans--;
    cout << ans << endl;
  } else {
    cout << "1" << endl;
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
