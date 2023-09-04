#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;

  if (x > y) {
    cout << "0 0" << endl;
    return;
  }
  
  if (x == y) {
    cout << "2 1" << endl;
    return;
  }

  if (y % x != 0) {
    cout << "0 0" << endl;
    return;
  }

  int d = y / x;
  cout << "1 " << d << endl;
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
