#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string x, y;
  cin >> x >> y;
  int n = x.length();
  
  vector<vector<int>> dp(n+1, vector<int>(2));
  for (int i = n-1; i >= 0; --i) {
    for (int p = 0; p < 2; ++p) {
      int xi = x[i] - '0';
      int p1 = (p + xi) % 2;
      int p2 = (p + (1-xi)) % 2;
      int yi = y[i] - '0';
      dp[i][p] = min(dp[i+1][p1] + (yi != p1), dp[i+1][p2] + (yi != p2) + 1);
    }
  }

  int ans = dp[0][0];
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
