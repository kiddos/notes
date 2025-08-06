#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<i64> dp(n+1);
  i64 ans = 0;
  for (int i = n; i >= 1; --i) {
    if (a[i] + i > n) {
      dp[i] = a[i];
    } else {
      dp[i] = dp[i + a[i]] + a[i];
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
