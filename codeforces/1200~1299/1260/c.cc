#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 r = 0, b = 0, k = 0;
  cin >> r >> b >> k;
  i64 larger = max(r, b);
  i64 smaller = min(r, b);
  if (larger / smaller < k) {
    cout << "OBEY" << endl;
  } else {
    cout << "REBEL" << endl;
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
