#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;

void solve() {
  int n = 0, k = 0, d = 0;
  cin >> n >> k >> d;

  vector<vector<i64>> dp(n+1, vector<i64>(2));
  dp[0][0] = 1;
  for (int w = 0; w <= n; ++w) {
    for (int has_d = 0; has_d < 2; ++has_d) {
      for (int i = 1; i <= k; ++i) {
        if (w+i <= n) {
          dp[w+i][has_d || i >= d] += dp[w][has_d];
          dp[w+i][has_d || i >= d] %= MOD;
        }
      }
    }
  }
  cout << dp[n][1] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
