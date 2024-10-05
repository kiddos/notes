#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k2 = 0, k3 = 0, k5 = 0, k6 = 0;
  cin >> k2 >> k3 >> k5 >> k6;
  i64 x = min({k2, k5, k6});
  k2 -= x;
  k5 -= x;
  k6 -= x;
  i64 y = min({k2, k3});
  k2 -= y;
  k3 -= y;
  i64 ans = x * 256 + y * 32;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
