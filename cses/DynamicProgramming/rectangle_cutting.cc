#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;

  // vector<vector<int>> memo(a+1, vector<int>(b+1, -1));
  // auto dp = [&](const auto& self, int i, int j) -> int {
  //   if (i == j) {
  //     return 0;
  //   }
  //   if (memo[i][j] >= 0) {
  //     return memo[i][j];
  //   }
  //   int ans = numeric_limits<int>::max();
  //   for (int w = 1; w < i; ++w) {
  //     ans = min(ans, self(self, w, j) + self(self, i-w, j) + 1);
  //   }
  //   for (int h = 1; h < j; ++h) {
  //     ans = min(ans, self(self, i, h) + self(self, i, j-h) + 1);
  //   }
  //   return memo[i][j] = ans;
  // };
  // int ans = dp(dp, a, b);
  constexpr int inf = 1e9;
  vector<vector<int>> dp(a+1, vector<int>(b+1, inf));
  for (int i = 0; i <= min(a, b); ++i) {
    dp[i][i] = 0;
  }
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      if (i != j) {
        for (int w = 1; w < i; ++w) {
          dp[i][j] = min(dp[i][j], dp[w][j] + dp[i-w][j] + 1);
        }
        for (int h = 1; h < j; ++h) {
          dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j-h] + 1);
        }
      }
    }
  }

  int ans = dp[a][b];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
