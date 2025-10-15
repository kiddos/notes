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
  vector<i64> p2(n+1, 1);
  constexpr int MOD = 1e9 + 7;
  for (int i = 1; i <= n; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }

  vector<vector<i64>> dp(n+1, vector<i64>(n+1));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    vector<vector<i64>> dp2 = dp;
    for (int x = 0; x <= n; ++x) {
      for (int y = 0; y <= n; ++y) {
        if (y > a[i]) {
          continue;
        }
        if (x <= a[i]) {
          // case 1. add a[i] to red
          dp2[a[i]][y] += dp[x][y];
          dp2[a[i]][y] %= MOD;
        } else {
          // case 2. add a[i] to blue
          dp2[x][a[i]] += dp[x][y];
          dp2[x][a[i]] %= MOD;
        }
      }
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  for (int x = 0; x <= n; ++x) {
    for (int y = 0; y <= n; ++y) {
      ans += dp[x][y];
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
