#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, b = 0, mod = 0;
  cin >> n >> m >> b >> mod;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<i64>> dp(m+1, vector<i64>(b+1));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = a[i]; k <= b; ++k) {
        dp[j][k] += dp[j-1][k-a[i]];
        dp[j][k] %= mod;
      }
    }
  }

  i64 ans = 0;
  for (int k = 0; k <= b; ++k) {
    ans += dp[m][k];
    ans %= mod;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
