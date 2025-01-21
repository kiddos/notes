#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 A = 0, B = 0;
  cin >> A >> B;
  if (A == 1 && B == 1) {
    cout << "NO" << endl;
  } else if (A == 1) {
    i64 x = A + B, y = B;
    i64 z = x + y;
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
  } else if (B == 1) {
    cout << "NO" << endl;
  } else {
    i64 p = A * B;
    i64 x = A, y = p;
    i64 z = x + y;
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
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
