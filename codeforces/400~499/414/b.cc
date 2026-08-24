#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> dp(n+1, 1);
  for (int i = 1; i < k; ++i) {
    vector<i64> dp2(n+1);
    for (int x = 1; x <= n; ++x) {
      for (int x2 = x; x2 <= n; x2 += x) {
        dp2[x] += dp[x2];
        dp2[x] %= MOD;
      }
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[i];
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
