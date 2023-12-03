#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  if (l == r) {
    if (l % 2 == 1) {
      for (int k = 2; k <= sqrt(l); ++k) {
        int a = k, b = l - k;
        if (gcd(a, b) > 1) {
          cout << a << " " << b << endl;
          return;
        }
      }
      cout << "-1" << endl;
    } else {
      if (l / 2 == 1) {
        cout << "-1" << endl;
      } else {
        cout << l / 2 << " " << l / 2 << endl;
      }
    }
  } else {
    int k = r;
    if (k % 2 == 1) k--;
    int ans = k / 2;
    if (ans == 1) {
      cout << "-1" << endl;
    } else {
      cout << ans << " " << ans << endl;
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
