#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

// 1010   10
// 1001    9
// 1000    8
// 0111    7
// 0110
// 0101
// 0100
// 0011
// 0010

void solve() {
  i64 n = 0, x = 0;
  cin >> n >> x;

  i64 ans = 0;
  if (x % 2 == 1) {
    // (x-1) ^ x ^ (x+1) ^ (x+2)
    // (x-3) ^ (x-2) ^ (x-1) ^ x
    if (x-1 >= 0 && x+2 <= n) {
      i64 right = n-(x+2);
      i64 left = x-1;
      ans += (((left / 4) % MOD) + 1) * ((right / 4) % MOD + 1);
      ans %= MOD;
    }

    if (x-3 >= 0) {
      i64 right = n-x;
      i64 left = x-3;
      ans += (((left / 4) % MOD) + 1) * ((right / 4) % MOD + 1);
      ans %= MOD;
    }
  } else {
    // x ^ (x+1) ^ (x+2) ^ (x+3)
    // (x-2) ^ (x-1) ^ x ^ (x+1)

    if (x+3 <= n) {
      i64 right = n-(x+3);
      i64 left = x;
      ans += (((left / 4) % MOD) + 1) * ((right / 4) % MOD + 1);
      ans %= MOD;
    }

    if (x-2 >= 0 && x+1 <= n) {
      i64 right = n-(x+1);
      i64 left = x-2;
      ans += (((left / 4) % MOD) + 1) * ((right / 4) % MOD + 1);
      ans %= MOD;
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
