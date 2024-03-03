#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int INF = 10000000;
  vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> dp2(n+1, vector<int>(n+1, INF));

    for (int l = 0; l < n; ++l) {
      for (int r = 0; r < n; ++r) {
        int l2 = l > 0 ? l+1 : (r == 0 ? 1 : 0);
        int r2 = max(r-1, 0);
        dp2[l2][r2] = min(dp2[l2][r2], dp[l][r]);

        l2 = l > 0 ? l+1 : 0;
        r2 = max(r-1, 0);
        if (l2 <= a[i]) {
          l2 = 0;
        }
        dp2[l2][r2] = min(dp2[l2][r2], dp[l][r] + 1);

        l2 = l > 0 ? l+1 : 0;
        r2 = max(r-1, a[i]-1);
        dp2[l2][r2] = min(dp2[l2][r2], dp[l][r] + 1);
      }
    }

    dp = std::move(dp2);
  }

  int ans = INF;
  for (int i = 0; i <= n; ++i) {
    ans = min(ans, dp[0][i]);
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
