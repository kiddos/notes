#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, i64 n, int mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  int sum = (n + 1) * n / 2;
  if (sum % 2 != 0) {
    cout << "0" << endl;
    return;
  }
  int target = sum / 2;
  vector<i64> dp(target+1);
  dp[0] = 1;
  constexpr int MOD = 1e9 + 7;
  for (int x = 1; x <= n; ++x) {
    for (int val = target; val >= 0; --val) {
      if (val + x <= target) {
        dp[val+x] += dp[val];
        dp[val+x] %= MOD;
      }
    }
  }
  i64 ans = dp[target];
  ans *= power(2, MOD-2, MOD);
  ans %= MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
