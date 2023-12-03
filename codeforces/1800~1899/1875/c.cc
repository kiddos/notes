#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;

  n %= m;

  i64 g = gcd(n, m);
  if (m % g != 0) {
    cout << "-1" << endl;
    return;
  }
  i64 p = m / g;
  if (bitset<64>(p).count() != 1) {
    cout << "-1" << endl;
    return;
  }

  i64 q = n / g;
  i64 bits = bitset<64>(q).count();
  i64 ans = bits * m - n;
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
