#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 0 -> -1 -> 1 -> 4 -> 0 -> -5 -> 1 -> 8 -> 0
// 1 -> 2 -> 0 -> -3 -> 1 -> 6 -> 0 -> -7 -> 1

void solve() {
  i64 x0 = 0, n = 0;
  cin >> x0 >> n;
  if (abs(x0) % 2 == 1) {
    if (n % 4 == 0) {
      cout << x0 << endl;
    } else if (n % 4 == 1) {
      cout << x0 + n << endl;
    } else if (n % 4 == 2) {
      cout << x0 - 1 << endl;
    } else if (n % 4 == 3) {
      cout << x0-n-1 << endl;
    }
  } else {
    if (n % 4 == 0) {
      cout << x0 << endl;
    } else if (n % 4 == 1) {
      cout << x0 - n << endl;
    } else if (n % 4 == 2) {
      cout << x0 + 1 << endl;
    } else if (n % 4 == 3) {
      cout << x0 + n+1 << endl;
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
