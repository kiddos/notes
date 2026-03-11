#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1 -> 1
// 2 -> 2
// 3 -> 3
// 4 -> 3
// 5 -> 4
// 6 -> 4
// 7 -> 5
// 8 -> 4

i64 C(i64 n, i64 k) {
  i64 k1 = max(n-k, k);
  i64 k2 = min(n-k, k);
  i64 ans = 1;
  for (i64 i = n; i > k1; --i) {
    ans *= i;
    while (k2 > 1 && ans % k2 == 0) {
      ans /= k2;
      k2--;
    }
  }
  // cout << "C(" << n << "," << k << ")=" << ans << endl;
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  i64 ans = 0;
  for (i64 d = 1, op = 1, zeros = 0; d <= n; d <<= 1, ++op, ++zeros) {
    i64 require_ops = max(k+1 - op, 0LL);
    if (d == n) {
      if (op > k) {
        ans++;
      }
    } else {
      for (int z = require_ops; z <= zeros; ++z) {
        ans += C(zeros, z);
      }
    }
    // cout << "d=" << d << ": " <<  ans << endl;
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
