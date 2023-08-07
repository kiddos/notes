#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n+1);
  for (int i = 1; i <= n; ++i) cin >> x[i];

  array<int, 4> ans = {0, 0, 0, 0};
  map<int,array<int,4>> dp;
  for (int i = 1; i <= n; ++i) {
    if (!dp.count(x[i])) {
      dp[x[i]] = {1, x[i], i, i};
    } else {
      auto [money, _, l, r] = dp[x[i]];
      int half = i-r-1;
      if (money <= half) {
        dp[x[i]] = {1, x[i], i, i};
      } else {
        money = max(0, money - half) + 1;
        dp[x[i]] = {money, x[i], l, i};
      }
    }
    ans = max(ans, dp[x[i]]);
  }

  cout << ans[1] << " " << ans[2] << " " << ans[3] << endl;
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
