#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, x = 0;
  cin >> n >> x;
  // 1 -> 1, 2 -> 2, 3 -> 3, ..., 8 -> 8, 9 -> 9
  // 10-> 1, 11 -> 2, 12 -> 3, ... 18 -> 9,
  // 19 -> 1, 20 -> 2, 21 -> 3, ... 27 -> 9
  i64 ans = (n-1) * 9 + x;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // function<int(int)> S = [&](int x) -> int {
  //   if (x < 10) {
  //     return x;
  //   }
  //   int d = 0;
  //   while (x > 0) {
  //     d += x % 10;
  //     x /= 10;
  //   }
  //   return S(d);
  // };
  //
  // for (int i = 10; i <= 100; ++i) {
  //   int root = S(i);
  //   cout << root << " ";
  // }
  // cout << endl;

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
