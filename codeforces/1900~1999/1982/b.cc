#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0, k = 0;
  cin >> x >> y >> k;

  while (k > 0 && x >= y) {
    int mod = x % y;
    int d = y - mod;
    // cout << "x=" << x << ",y=" << y << ",k=" << k << ",d=" << d << endl;
    if (k < d) {
      cout << x + k << endl;
      return;
    }
    
    x += d;
    while (x % y == 0) {
      x /= y;
    }
    k -= d;
  }


  if (k > 0) {
    int d = y - x;
    if (k < d) {
      cout << x + k << endl;
      return;
    }

    x = 1;
    k -= d;
    int mod1 = y-1;
    k %= mod1;
    x += k;
  }
  cout << x << endl;
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
