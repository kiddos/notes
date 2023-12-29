#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];
  vector<array<int,3>> activities;
  for (int i = 0; i < n; ++i) {
    activities.push_back({a[i], b[i], c[i]});
  }

  vector<i64> dp(8, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<i64> dp2 = dp;
    for (int mask = 0; mask < 8; ++mask) {
      for (int b = 0; b < 3; ++b) if (!(mask & (1<<b))) {
        int mask2 = mask | (1<<b);
        if (dp[mask] >= 0) {
          dp2[mask2] = max(dp2[mask2], dp[mask] + activities[i][b]);
        }
      }
    }

    dp = move(dp2);
  }

  i64 ans = dp[7];
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
