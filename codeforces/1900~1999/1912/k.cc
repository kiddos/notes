#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ans = 0;
  vector<vector<i64>> dp(2, vector<i64>(2));
  vector<i64> count(2);
  constexpr int MOD = 998244353;
  for (int i = 0; i < n; ++i) {
    int p = a[i] % 2;
    vector<vector<i64>> dp2(2, vector<i64>(2));
    for (int b1 = 0; b1 < 2; ++b1) {
      for (int b2 = 0; b2 < 2; ++b2) {
        dp2[b1][b2] += dp[b1][b2];
        dp2[b1][b2] %= MOD;
        if ((b1 + b2 + p) % 2 == 0) {
          dp2[b2][p] += dp[b1][b2];
          dp2[b2][p] %= MOD;
          ans += dp[b1][b2];
          ans %= MOD;
        }
      }
    }
    for (int b = 0; b < 2; ++b) {
      dp2[b][p] += count[b];
      dp2[b][p] %= MOD;
    }
    count[p] ++;

    dp = std::move(dp2);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
