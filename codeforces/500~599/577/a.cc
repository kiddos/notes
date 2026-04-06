#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;

  int ans = 0;
  for (int d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      int d1 = d;
      int d2 = x / d;
      if (d1 <= n && d2 <= n) {
        if (d1 == d2) {
          ans++;
        } else {
          ans += 2;
        }
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
