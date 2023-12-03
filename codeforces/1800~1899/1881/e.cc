#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> dp(n+2);
  for (int i = 1; i <= n; ++i) {
    dp[i+1] = max(dp[i+1], dp[i]);
    if (i+a[i]+1 <= n+1) {
      dp[i+a[i]+1] = max(dp[i+a[i]+1], dp[i] + a[i] + 1);
    }
  }
  // for (int i = 0; i < dp.size(); ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  int ans = n;
  for (int i = 1; i <= n+1; ++i) {
    ans = min(ans, n - dp[i]);
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
