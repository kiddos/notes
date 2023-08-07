#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> dp(n+1);
  map<int, array<int, 3>> remove;
  for (int i = n-1; i >= 0; --i) {
    dp[i] = dp[i+1];
    // for (int j = i+1; j < n; ++j) {
    //   if (a[i] == a[j]) {
    //     int len = j-i+1;
    //     dp[i] = max(dp[i], dp[j+1] + len);
    //   }
    // }
    if (remove.count(a[i])) {
      auto [sum, r, j] = remove[a[i]];
      dp[i] = max(dp[i], r + j-i+1);
    }
    array<int, 3> r = {dp[i+1]+i, dp[i+1], i};
    remove[a[i]] = max(remove[a[i]], r);
  }

  int ans = dp[0];
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
