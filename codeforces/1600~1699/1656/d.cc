#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  for (i64 k = 2;; k <<= 1) {
    i64 sum = k * (k+1) / 2;
    if (sum > n) {
      break;
    }
    if ((n - sum) % k == 0) {
      cout << k << endl;
      return;
    }
  }

  i64 k1 = n;
  while (k1 % 2 == 0) {
    k1 /= 2;
  }
  if (k1 == 1) {
    cout << "-1" << endl;
    return;
  }
  if (k1 * (k1+1) / 2 <= n) {
    cout << k1 << endl;
  } else {
    i64 k2 = 2 * (n / k1);
    cout << k2 << endl;
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
