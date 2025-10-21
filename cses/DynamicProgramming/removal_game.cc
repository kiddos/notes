#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<vector<i64>> dp(n, vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = x[i];
  }

  for (int len = 2; len <= n; ++len) {
    for (int l = 0; l <= n-len; ++l) {
      int r = l + len-1;
      dp[l][r] = max(x[l] - dp[l+1][r], x[r] - dp[l][r-1]);
    }
  }

  i64 diff = dp[0][n-1];
  i64 total = accumulate(x.begin(), x.end(), 0LL);
  // x - y = diff
  // x + y = total
  // 2x = diff + total
  // x = (diff + total) / 2
  i64 first = (diff + total) / 2;
  cout << first << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
