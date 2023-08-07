#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  vector<vector<int>> dp(n+1, vector<int>(2));
  for (int i = 1; i <= n; ++i) {
    int p = i % 2;
    dp[c[i]][p] = dp[c[i]][1-p] + 1;
  }

  for (int i = 1; i <= n; ++i) {
    cout << max(dp[i][0], dp[i][1]) << " ";
  } 
  cout << endl;
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
