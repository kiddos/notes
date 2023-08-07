#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<i64> a(n+1);

  for (int i = 1; i <= n; ++i) cin >> a[i];

  if (k == 1) {
    cout << (n-1) / 2 << endl;
    return;
  }

  vector<int> dp(n+1);
  for (int i = 2; i <= n-1; ++i) {
    if (a[i] > a[i-1] + a[i+1]) {
      dp[i] = max(dp[i-1], dp[i-2] + 1);
    } else {
      dp[i] = dp[i-1];
    }
  }

  cout << dp[n-1] << endl;
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
