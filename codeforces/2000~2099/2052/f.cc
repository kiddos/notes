#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(2);
  for (int i = 0; i < 2; ++i) {
    cin >> s[i];
  }

  // dp[i][0] means #ways to fill both rows at i column
  // dp[i][1] means #ways to fill only first row at i column
  // dp[i][2] means #ways to fill only second row at i column
  vector<vector<int>> dp(n+1, vector<int>(3));
  dp[0][0] = 1;
  constexpr int inf = 1000000;
  for (int i = 1; i <= n; ++i) {
    if (i >= 2) {
      string grid = s[0].substr(i-2, 2) + s[1].substr(i-2, 2);
      if (grid == "....") {
        dp[i][0] += dp[i-2][0];
        dp[i][1] += dp[i-1][2];
        dp[i][2] += dp[i-1][1];
      } else if (grid == "..#.") {
        // ..
        // #.
        dp[i][1] += dp[i-2][0];
      } else if (grid == "#...") {
        // #.
        // ..
        dp[i][2] += dp[i-2][0];
      }
    }
    string grid = s[0].substr(i-1, 1) + s[1].substr(i-1, 1);
    if (grid == ".." || grid == "##") {
      dp[i][0] += dp[i-1][0];
    } else if (grid == ".#") {
      dp[i][2] += dp[i-1][0];
      dp[i][0] += dp[i-1][2];
    } else if (grid == "#.") {
      dp[i][1] += dp[i-1][0];
      dp[i][0] += dp[i-1][1];
    }

    for (int k = 0; k < 3; ++k) {
      dp[i][k] = min(dp[i][k], inf);
    }
    // cout << dp[i][0] << "," << dp[i][1] << ","<< dp[i][2] << endl;
  }

  if (dp[n][0] == 0) {
    cout << "None" << endl;
  } else if (dp[n][0] == 1) {
    cout << "Unique" << endl;
  } else if (dp[n][0] > 1) {
    cout << "Multiple" << endl;
  }
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
