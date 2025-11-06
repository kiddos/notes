#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  int m = 1 << n;
  vector<pair<int,i64>> dp(m, {n+1, 0});
  dp[0] = {1, 0};
  for (int mask = 0; mask < m; ++mask) {
    for (int b = 0; b < n; ++b) {
      if (!(mask & (1<<b))) {
        auto [min_ride, min_weight] = dp[mask];
        int mask2 = mask | (1<<b);
        if (min_weight + w[b] > x) {
          dp[mask2] = min(dp[mask2], {min_ride+1, w[b]});
        } else {
          dp[mask2] = min(dp[mask2], {min_ride, min_weight + w[b]});
        }
      }
    }
  }

  int ans = dp[m-1].first;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
