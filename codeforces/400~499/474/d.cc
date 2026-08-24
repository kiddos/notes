#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;

void solve() {
  int t = 0, k = 0;
  cin >> t >> k;
  vector<int> a(t), b(t);
  for (int i = 0; i < t; ++i) {
    cin >> a[i] >> b[i];
  }

  int max_val = *max_element(b.begin(), b.end());
  vector<i64> dp(max_val+1);
  dp[0] = 1;
  for (int i = 1; i <= max_val; ++i) {
    dp[i] += dp[i-1];
    if (i >= k) {
      dp[i] += dp[i-k];
      dp[i] %= MOD;
    }
  }

  vector<i64> prefix_dp = dp;
  for (int i = 1; i <= max_val; ++i) {
    prefix_dp[i] += prefix_dp[i-1];
    prefix_dp[i] %= MOD;
  }

  vector<i64> ans(t);
  for (int i = 0; i < t; ++i) {
    ans[i] = prefix_dp[b[i]] + (MOD - prefix_dp[a[i]-1]);
    ans[i] %= MOD;
  }

  for (int i = 0; i < t; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
