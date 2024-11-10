#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(2);
  cin >> s[0] >> s[1];

  auto most_vote = [&](char c1, char c2, char c3) -> int {
    int total = (c1 == 'A') + (c2 == 'A') + (c3 == 'A');
    return total >= 2;
  };

  vector<vector<int>> dp(n+1, vector<int>(3, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    if (i+1 < n) {
      if (dp[i][0] >= 0) {
        dp[i+1][1] = max(dp[i+1][1], most_vote(s[0][i], s[0][i+1], s[1][i]) + dp[i][0]);
        dp[i+1][2] = max(dp[i+1][2], most_vote(s[0][i], s[1][i], s[1][i+1]) + dp[i][0]);
      }
      if (dp[i][1] >= 0) {
        dp[i+2][0] = max(dp[i+2][0], most_vote(s[0][i+1], s[1][i], s[1][i+1]) + dp[i][1]);
      }
      if (dp[i][2] >= 0) {
        dp[i+2][0] = max(dp[i+2][0], most_vote(s[0][i], s[0][i+1], s[1][i+1]) + dp[i][2]);
      }
    }

    if (i+2 < n && dp[i][0] >= 0) {
      dp[i+3][0] = max(dp[i+3][0],
                        most_vote(s[0][i], s[0][i+1], s[0][i+2]) +
                        most_vote(s[1][i], s[1][i+1], s[1][i+2]) + dp[i][0]);
    }
    if (i+3 < n && dp[i][1] >= 0) {
      dp[i+3][1] = max(dp[i+3][1],
                        most_vote(s[0][i+1], s[0][i+2], s[0][i+3]) +
                        most_vote(s[1][i], s[1][i+1], s[1][i+2]) + dp[i][1]);
    }
    if (i+3 < n && dp[i][2] >= 0) {
      dp[i+3][2] = max(dp[i+3][2],
                        most_vote(s[0][i], s[0][i+1], s[0][i+2]) +
                        most_vote(s[1][i+1], s[1][i+2], s[1][i+3]) + dp[i][2]);
    }
  }

  // for (int k = 0; k < 3; ++k) {
  //   for (int i = 0; i <= n; ++i) {
  //     cout << dp[i][k] << " ";
  //   }
  //   cout << endl;
  // }

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
