#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);
  int xa = 0, ya = 0, xb = 0, yb = 0, xf = 0, yf = 0;
  cin >> xa >> ya >> xb >> yb >> xf >> yf;

  int dist = abs(xa - xb) + abs(ya - yb);
  if ((xa == xb && xa == xf && min(ya, yb) < yf && max(ya, yb) > yf) ||
      (ya == yb && ya == yf && min(xa, xb) < xf && max(xa, xb) > xf)) {
    dist += 2;
  }
  cout << dist << endl;
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
