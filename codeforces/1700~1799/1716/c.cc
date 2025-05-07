#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  a[0][0] = -1;
  vector<vector<int>> dp(2, vector<int>(n+1));
  for (int j = n-1; j >= 0; --j) {
    for (int i = 0; i < 2; ++i) {
      dp[i][j] = max(max(a[i][j] + 2 * (n - j), a[1-i][j] + 1), dp[i][j+1] + 1);
    }
  }
  
  // for (int i = 0; i < 2; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int current = 0;
  int ans = numeric_limits<int>::max();
  for (int j = 0; j < n; ++j) {
    int k = j % 2;
    ans = min(ans, max(current, dp[k][j]));
    current = max(current, a[k][j] + (n-j) * 2);
    current = max(current, a[1-k][j] + (n-j) * 2 - 1);
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
