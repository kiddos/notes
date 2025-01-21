#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  // if (k == 1) {
  //   i64 ans = (n+1) * n / 2;
  //   cout << ans << endl;
  //   return;
  // }

  i64 len = n;
  i64 starts = 1, count = 1;
  i64 ans = 0;
  while (len >= k) {
    if (len % 2 == 1) {
      i64 half = len / 2;
      ans += starts + count * half;

      starts = starts * 2 + (half+1) * count;
      count *= 2;
    } else {
      i64 half = len / 2;
      starts = starts * 2 + half * count;
      count *= 2;
    }

    len /= 2;
  }

  // function<i64(int,int)> divide = [&](int l, int r) -> i64 {
  //   int len = r-l+1;
  //   if (len < k) return 0;
  //   int m = (l + r) / 2;
  //   if (len % 2 == 1) {
  //     return divide(l, m-1) + divide(m+1, r) + m;
  //   }
  //   return divide(l, m) + divide(m+1, r);
  // };
  cout << ans << endl;
  // cout << divide(1, n) << endl;
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
