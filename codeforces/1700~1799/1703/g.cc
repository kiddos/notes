#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  ll k = 0;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll MIN_VAL = -1e18;
  vector<ll> dp(32, MIN_VAL);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<ll> next_dp(32, MIN_VAL);
    for (int s = 0; s <= min(i+1, 31); ++s) {
      next_dp[s] = max(next_dp[s], dp[s] + (a[i] >> s) - k);
      int s2 = min(s+1, 31);
      next_dp[s2] = max(next_dp[s2], dp[s] + (a[i] >> s2));
    }
    dp = move(next_dp);
  }

  ll ans = *max_element(dp.begin(), dp.end());
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
