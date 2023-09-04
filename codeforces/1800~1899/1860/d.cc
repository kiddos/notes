#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();

  constexpr int INF = 1e9;
  vector<vector<int>> dp(n+1, vector<int>(n*n, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> next_dp(n+1, vector<int>(n*n, INF));

    for (int j = 0; j <= i; ++j) {
      for (int c01 = 0; c01+j < n*n; ++c01) {
        next_dp[j+1][c01] = min(next_dp[j+1][c01], dp[j][c01] + (s[i] != '0'));
        next_dp[j][c01+j] = min(next_dp[j][c01+j], dp[j][c01] + (s[i] != '1'));
      }
    }

    dp = move(next_dp);
  }

  int c0 = count(s.begin(), s.end(), '0');
  cout << dp[c0][c0 * (n-c0) / 2] / 2<< endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
