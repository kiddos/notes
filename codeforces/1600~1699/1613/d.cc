#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [0, ...]
// [1, ...]
// [0, ..., 2, ...]
// [0, ..., 1, ...]
// [0, ..., 1, ..., 2, ....]
// [0, ..., 1, ..., 3, ....]

constexpr int MOD = 998244353;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    n >>= 1;
    x = x * x;
    x %= MOD;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 ans = 0;
  vector<int> counts(n+1);
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;
  }

  vector<i64> dp(n+1);
  int left_zero = 0;
  for (int i = 0; i < n; ++i) {
    counts[a[i]]--;
    if (a[i] == 0) {
      ans += power(2, counts[a[i]]);
      ans %= MOD;
    } else if (a[i] == 1) {
      ans += power(2, counts[a[i]]);
      ans %= MOD;

      ans += dp[a[i]-1] * power(2, counts[a[i]]);
      ans %= MOD;
    } else {
      ans += dp[a[i]-1] * power(2, counts[a[i]]);
      ans %= MOD;

      ans += dp[a[i]-2] * power(2, counts[a[i]] + counts[a[i] - 2]);
      ans %= MOD;
    }

    if (a[i] == 0) {
      dp[0] += power(2, left_zero);
      dp[0] %= MOD;
      left_zero++;
    } else {
      dp[a[i]] = dp[a[i]-1] + dp[a[i]] * 2;
      dp[a[i]] %= MOD;
    }

    // cout << "i=" << i << ", a[i]=" << a[i] << " ";
    // cout << "dp=" << dp[a[i]] << ", ans=" << ans << endl;
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
