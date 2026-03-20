#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 p = 0, q = 0;
  cin >> p >> q;
  // find n where p - 2 * n = q - 3 * n
  // and bob and win
  i64 n = q - p;
  i64 p0 = 2 * n, q0 = 3 * n;
  if (p0 >= 0 && p0 <= p && q0 >= 1 && q0 <= q) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
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
