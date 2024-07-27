#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution1 {
 public:
  int countPairs(int n, int k) {
    if (k == 0) return 1;
    if (n == 1) return k == 0;
    if (memo_[n-1][k]) return memo_[n-1][k];

    int ans = 0;
    for (int i = 0; i <= min(n-1, k); ++i) {
      ans += countPairs(n-1, k-i);
      ans %= MOD;
    }
    memo_[n-1][k] = ans;
    return ans;
  }

  int kInversePairs(int n, int k) {
    memo_ = vector<vector<int>>(n, vector<int>(k+1));
    return countPairs(n, k);
  }

 private:
  vector<vector<int>> memo_;
};

class Solution2 {
 public:
  int kInversePairs(int n, int k) {
    vector<vector<int>> dp(n, vector<int>(k+1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (j == 0) dp[i][j] = 1;
        else if (i > 0) {
          for (int m = 0; m <= min(i, j); ++m) {
            dp[i][j] += dp[i-1][j-m];
            dp[i][j] %= MOD;
          }
        }
      }
    }
    return dp[n-1][k];
  }
};

class Solution3 {
 public:
  int kInversePairs(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (j == 0) dp[i][j] = 1;
        else {
          int val = dp[i-1][j] - (j >= i ? dp[i-1][j-i] : 0);
          val = (val + MOD) % MOD;
          dp[i][j] = dp[i][j-1] + val;
          dp[i][j] %= MOD;
        }
      }
    }
    return (dp[n][k] - dp[n][k-1] + MOD) % MOD;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    // int ans = Solution1().kInversePairs(n, k);
    // cout << "answer1: " << ans << endl;

    // ans = Solution2().kInversePairs(n, k);
    // cout << "answer2: " << ans << endl;

    int ans = Solution3().kInversePairs(n, k);
    cout << "answer3: " << ans << endl;
  }
  return 0;
}
