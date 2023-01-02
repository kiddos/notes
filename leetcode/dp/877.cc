#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) dp[i][i] = piles[i];
    for (int len = 1; len < n; ++len) {
      for (int i = 0; i < n-len; ++i) {
        int j = i+len;
        dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
      }
    }

    return dp[0][n-1] > 0;
  }
};

class Solution2 {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<int> dp = piles;
    for (int len = 1; len < n; ++len) {
      for (int i = 0; i < n-len; ++i) {
        int j = i+len;
        dp[i] = max(piles[i] - dp[i+1], piles[j] - dp[i]);
      }
    }
    return dp.back();
  }
};

class Solution3 {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) dp[i][i] = {piles[i], 0};
    for (int len = 1; len < n; ++len) {
      for (int i = 0; i < n-len; ++i) {
        int j = i+len;
        int f = piles[i] + dp[i+1][j].second;
        int s = piles[j] + dp[i][j-1].second;
        if (f > s) {
          dp[i][j].first = f;
          dp[i][j].second = dp[i+1][j].first;
        } else {
          dp[i][j].first = s;
          dp[i][j].second = dp[i][j-1].first;
        }
      }
    }
    return dp[0][n-1].first > dp[0][n-1].second;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> piles = { 5,3,4,5 };
  bool ans = Solution1().stoneGame(piles);
  assert(ans);
  ans = Solution2().stoneGame(piles);
  assert(ans);
  ans = Solution3().stoneGame(piles);
  assert(ans);

  piles = { 1,2,3,4,5,6 };
  ans = Solution1().stoneGame(piles);
  assert(ans);
  ans = Solution2().stoneGame(piles);
  assert(ans);
  ans = Solution3().stoneGame(piles);
  assert(ans);

  piles = { 3,3,2,3 };
  ans = Solution1().stoneGame(piles);
  assert(ans);
  ans = Solution2().stoneGame(piles);
  assert(ans);
  ans = Solution3().stoneGame(piles);
  assert(ans);

  piles = { 1,2,2,1,1,1,3,1,3,13,2,31,24,12,31,23,2,1,2,312,3,124,43,43 };
  ans = Solution1().stoneGame(piles);
  assert(ans);
  ans = Solution2().stoneGame(piles);
  assert(ans);

  piles = { 3,7,2,3 };
  ans = Solution1().stoneGame(piles);
  assert(ans);
  ans = Solution2().stoneGame(piles);
  assert(ans);
  ans = Solution3().stoneGame(piles);
  assert(ans);

  piles = { 7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24 };
  ans = Solution1().stoneGame(piles);
  assert(ans);
  ans = Solution2().stoneGame(piles);
  assert(ans);
  ans = Solution3().stoneGame(piles);
  assert(ans);
  return 0;
}
