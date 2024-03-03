#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 h = 0, w = 0, xa = 0, ya = 0, xb = 0, yb = 0;
  cin >> h >> w >> xa >> ya >> xb >> yb;

  if (xa >= xb) {
    cout << "Draw" << endl;
    return;
  }

  i64 a = xa, b = xb;
  pair<i64,i64> ra = {ya, ya};
  pair<i64,i64> rb = {yb, yb};
  while (true) {
    a++;
    ra.first = max(ra.first - 1, 1LL);
    ra.second = min(ra.second + 1, w);
    if (a == b) {
      // alice capture bob
      if (rb.second > ra.second || rb.first < ra.first) {
        // bob can escape
        cout << "Draw" << endl;
      } else {
        cout << "Alice" << endl;
      }
      return;
    }

    b--;
    rb.first = max(rb.first - 1, 1LL);
    rb.second = min(rb.second + 1, w);
    if (a == b) {
      // bob capture alice
      if (ra.second > rb.second || ra.first < rb.first) {
        // alice can escape
        cout << "Draw" << endl;
      } else {
        cout << "Bob" << endl;
      }
      break;
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
