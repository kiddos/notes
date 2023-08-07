#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<ll> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  vector<ll> dp = c;
  ll ans = dp[1];
  for (int i = 2; i <= n; ++i) {
    dp[i] = max({dp[i-2] + c[i], dp[i]});
    if (i > 2) {
      dp[i] = max(dp[i], dp[i-2]);
    }
    ans = max(ans, dp[i]);
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
