#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  // S = x * (2^k - 1)
  for (i64 k = 2; k < 30; ++k) {
    i64 p2 = (1 << k) - 1;
    if (n % p2 == 0) {
      cout << n / p2 << endl;
      return;
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
