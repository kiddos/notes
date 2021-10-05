#include <bits/stdc++.h>

using namespace std;

// Distinct Subsequences
//
// I struggle a little on this dp state transition
// dp[i][j] = number of ways to get t[:j] from s[:i] susbstring
//
// base case: if t has len = 0, dp[i][0] = 1
//
// the answer matching t[:j] to s[:i] should continue from s[:i-1]
//  dp[i][j] += dp[i-1][j]
// if s[i] == t[j]:
//  dp[i][j] += dp[i-1][j-1]
//
// This problem has a really weird test case where dp[i][j] may overflow
// since the problem says the answer is guaranteed to fit in 32bit int
// we can add if (dp[i][j] > numeric_limits<int>::max()) continue;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    vector<vector<long>> dp(m + 1, vector<long>(n + 1));
    for (int i = 0; i <= m; ++i) dp[i][0] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] += dp[i - 1][j];
        if (dp[i][j] > numeric_limits<int>::max()) continue;
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] += dp[i - 1][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "rabbbit";
  string t = "rabbit";
  int ans = Solution().numDistinct(s, t);
  assert(ans == 3);

  s = "babgbag";
  t = "bag";
  ans = Solution().numDistinct(s, t);
  assert(ans == 5);

  // code here...
  return 0;
}
