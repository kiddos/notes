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

  int max_val = 8192;
  vector<vector<int>> dp(n+1, vector<int>(max_val));
  for (int i = 1; i <= n; ++i) {
    for (int x = 0; x < max_val; ++x) {
      dp[i][x] = dp[i-1][0] + (a[i] != x);
      dp[i][x] = min(dp[i][x], dp[i-1][a[i]^x] + 1);
    }
  }

  cout << dp[n][0] << endl;
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
