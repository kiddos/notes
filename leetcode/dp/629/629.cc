#include <bits/stdc++.h>

using namespace std;

// K Inverse Pairs Array
//
// this one is super hard DP
// first consider the edge case first
// when k == 0, there's only 1 way which is [1, 2, 3, ..., n]
// when n == 0, answer is 0
//
// when we have k == 0: [1, 2, 3, 4]
// only way to get to k == 0, with n+1 is adding 5 at the end: [1, 2, 3, 4, 5]
//
// when we have k == 1: [1, 3, 2], [2, 1, 3]
// to get to k == 1: we can add 4 for each of these like: [1, 3, 2, 4], [2, 1,
// 3, 4] -> dp(n-1, k) = 2
//                   or insert 4 for k == 0 like: [1, 2, 4, 3] -> dp(n-1, k-1) =
//                   1
//
// so
// for k == 1, answer should come from dp(n-1, 0), dp(n-1, 1)
// for k == 2, answer should come from dp(n-1, 0), dp(n-1, 1), dp(n-1, 2)
// for k == 3, answer should come from dp(n-1, 0), dp(n-1, 1), dp(n-1, 2),
// dp(n-1, 3) answer can only go up to min(n-1, k) like: dp(n-1, 0) + dp(n-1, 1)
// + dp(n-1, 2) + ... + dp(n-1, min(n-1, k))

// O(n^2*k)
class SolutionTLE {
 public:
  int topDown(int n, int k) {
    function<int(int, int)> dp = [&](int n, int k) {
      if (k == 0) return 1;
      if (n == 0) return 0;
      int ans = 0;
      for (int i = 0; i <= min(k, n - 1); ++i) {
        ans += dp(n - 1, k - i);
      }
      return ans;
    };
    return dp(n, k);
  }

  int bottomUp(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i) dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        for (int p = 0; p <= min(j, i - 1); ++p) {
          dp[i][j] += dp[i - 1][j - p];
        }
      }
    }
    return dp[n][k];
  }
};

// k == 1: dp(n, k) = dp(n-1, 0) + dp(n-1, 1)
// k == 2: dp(n, k) = dp(n-1, 0) + dp(n-1, 1) + dp(n-1, 2)
//                  = dp(n, 1) + dp(n-1, 2)
// k == 3: dp(n, k) = dp(n-1, 0) + dp(n-1, 1) + dp(n-1, 2) + dp(n-1, 3)
//                  = dp(n, 2) + dp(n-1, 3)
//
// same here we can only go up to min(n-1, k)
// => need to subtract extra part from dp(n-1, n) to dp(n-1, k) if k >= n
// so dp(n, k) = dp(n, k-1) + dp(n-1, k) - (k >= n ? dp(i-1, k-n) : 0)

class Solution {
 public:
  int kInversePairs(int n, int k) {
    vector<vector<long>> dp(n + 1, vector<long>(k + 1));
    const int MOD = 1e9 + 7;
    for (int i = 1; i <= n; ++i) dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j] +=
            dp[i][j - 1] + dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0);
        dp[i][j] = (dp[i][j] + MOD) % MOD;
      }
    }
    return (dp[n][k] - (k > 0 ? dp[n][k - 1] : 0) + MOD) % MOD;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans = Solution().kInversePairs(3, 0);
  assert(ans == 1);

  ans = Solution().kInversePairs(3, 1);
  assert(ans == 2);

  ans = Solution().kInversePairs(6, 3);
  assert(ans == 29);

  ans = Solution().kInversePairs(1000, 10);
  assert(ans == 158669030);
  return 0;
}
