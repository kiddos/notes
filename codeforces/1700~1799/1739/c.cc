#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  constexpr int MOD = 998244353;
  int n = 0;
  cin >> n;

  int k = n / 2;
  ll dp[61][61][3];
  memset(dp, 0, sizeof(dp));
  dp[0][0][2] = 1;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int t = 0; t < 3; ++t) {
        int turn = (i+j) % 4;
        if (turn == 0 || turn == 3) {
          if (i < k) dp[i+1][j][t == 2 ? 0 : t] += dp[i][j][t];
          if (j < k) dp[i][j+1][t] += dp[i][j][t];
        } else {
          if (i < k) dp[i+1][j][t] += dp[i][j][t];
          if (j < k) dp[i][j+1][t == 2 ? 1 : t] += dp[i][j][t];
        }
        dp[i+1][j][t] %= MOD;
        dp[i][j+1][t] %= MOD;
      }
    }
  }

  for (int t = 0; t < 3; ++t) {
    cout << dp[k][k][t]  << " ";
  }
  cout << endl;
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
