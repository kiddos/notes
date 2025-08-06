#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, l = 0, r = 0, k = 0;
  cin >> n >> l >> r >> k;
  if (n % 2 == 1) {
    // put l for the entire array
    cout << l << endl;
  } else {
    // find the smallest integer that bitwise and l is 0 and greater than l
    int msb = 0;
    for (int b = 62; b >= 0; --b) {
      if (l & (1LL<<b)) {
        msb = b;
        break;
      }
    }
    i64 x = 1LL<< (msb+1);
    if (x > r || n < 4) {
      cout << "-1" << endl;
    } else {
      // the last 2 element is x
      // the first n-2 element is l
      if (k <= n-2) {
        cout << l << endl;
      } else {
        cout << x << endl;
      }
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
