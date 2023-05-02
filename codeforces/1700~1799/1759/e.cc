#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, h = 0;
  cin >> n >> h;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> serum = {2, 2, 3};
  int m = 1 << serum.size();

  sort(a.begin(), a.end());
  int ans = 0;
  vector<pair<ll,int>> dp(m, {h, 0});
  for (int i = 0; i < n; ++i) {
    vector<pair<ll,int>> next_dp = dp;
    for (int m1 = 0; m1 < m; ++m1) {
      for (int m2 = 0; m2 < m; ++m2) if ((m1 | m2) <= m2) {
        int mul = 1;
        for (int b = 0; b < serum.size(); ++b) if ((m2 & (1<<b)) && !(m1 & (1<<b))) {
          mul *= serum[b];
        }
        ll h2 = dp[m1].first;
        if (h2 * mul > a[i]) {
          next_dp[m2] = max(next_dp[m2], {h2 * mul + a[i] / 2, dp[m1].second+1});
          ans = max(ans, next_dp[m2].second);
        }
      }
    }
    dp = move(next_dp);

    // for (int i = 0; i < 8; ++i) {
    //   cout << bitset<3>(i) << ":(" << dp[i].first << "," << dp[i].second << ")  ";
    // }
    // cout << endl;
  }

  // for (int i = 0; i < 8; ++i) {
  //   cout << bitset<3>(i) << ":(" << dp[i].first << "," << dp[i].second << ")  ";
  // }
  // cout << endl;

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
