#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  i64 ans = 0;
  for (i64 a = 1; a <= x - 2; ++a) {
    for (i64 b = 1; b <= x - a - 1 && a * b <= n; ++b) {
      i64 l = 1, r = x - a - b;
      i64 c = 0;
      while (l <= r) {
        i64 mid = l + (r-l) / 2;
        if (a * b + b * mid + mid * a <= n) {
          c = mid;
          l = mid + 1;
        } else {
          r = mid-1;
        }
      }
      ans += c;
    }
  }
  cout << ans << endl;
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
