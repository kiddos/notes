#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 300000;
constexpr int MOD = 1000000007;
vector<i64> dp(MAX_N+1);

// dp[0] = 1
// dp[1] = 1
// dp[2] = dp[1] + dp[0] * 2
//       = dp[1] + dp[0] * 2
//
// dp[3] = dp[2] + dp[1] * dp[1] + dp[1]
//       = dp[2] + dp[1] * 4
//
// dp[4] = dp[3] + dp[2] * 2 + dp[2] * 2 + dp[2] * 2
//       = dp[3] * 2 + dp[2] * 6
//
// dp[5] = dp[4] + dp[3] * 2 + dp[2] * dp[2] + dp[3] * 2 + dp[3] * 2
//       = dp[4] + dp[3] * 8
//
// dp[6] = dp[5] + dp[4] * 2 + dp[4] * 2 + dp[4] * 2 + dp[4] * 2 + dp[4] * 2
//       = dp[5] + dp[4] * 10

void precompute() {
  dp[0] = dp[1] = 1;
  dp[2] = 3;
  for (int i = 3; i <= MAX_N; ++i) {
    dp[i] = dp[i-1];
    dp[i] += (dp[i-2] * (i-1) * 2) % MOD;
    dp[i] %= MOD;
  }
  // for (int i = 1; i <= MAX_N; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> r(k), c(k);
  for (int i = 0; i < k; ++i) {
    cin >> r[i] >> c[i];
  }
  vector<bool> used_row(n+1), used_col(n+1);
  for (int i = 0; i < k; ++i) {
    used_row[r[i]] = true;
    used_col[c[i]] = true;

    if (r[i] != c[i]) {
      used_row[c[i]] = true;
      used_col[r[i]] = true;
    }
  }


  int empty = 0;
  for (int i = 1; i <= n; ++i) {
    if (!used_row[i]) {
      empty++;
    }
  }

  i64 ans = dp[empty];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
