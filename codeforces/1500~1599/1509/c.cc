#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<vector<i64>> dp(n, vector<i64>(n));
  for (int l = n-1; l >= 0; --l) {
    for (int r = l+1; r < n; ++r) {
      dp[l][r] = min(
        dp[l][r-1] + a[r] - a[l],
        dp[l+1][r] + a[r] - a[l]
      );
    }
  }
  i64 ans = dp[0][n-1];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
