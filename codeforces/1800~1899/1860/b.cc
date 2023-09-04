#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 m = 0, k = 0, a1 = 0, ak = 0;
  cin >> m >> k >> a1 >> ak;

  auto can_fill = [&]() {
    i64 k_coin = min(m / k, ak);
    i64 x = k_coin * k;
    i64 y = a1;
    return x + y >= m;
  };

  if (can_fill()) {
    cout << "0" << endl;
    return;
  }

  i64 ans = 0;
  // greedy fill with a1
  if (a1 >= m % k) {
    a1 -= m % k;
    ak += a1 / k;
  } else {
    ans += (m % k) - a1;
  }
  m -= m % k;

  // cout << "m=" << m << endl;
  i64 k_coin = m / k;
  ans += max(k_coin - ak, 0LL);

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
