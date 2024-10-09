#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;

  function<int(int)> f = [&](int x) -> int  {
    if (x <= 0) {
      return 0;
    }
    if (x % 2 == 0) {
      return x / 2;
    } else {
      return f(x-1) - x;
    }
  };

  int ans = f(r) - f(l-1);
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
