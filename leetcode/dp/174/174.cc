#include <bits/stdc++.h>

using namespace std;

// Dungeon Game
//
// I was stuck on this one for a bit.
// The trick is to think backwards.
// at the finish the health should be max(-dungeon[i][j] + 1, 1)
// and the dp transition should be
// dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1)

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (i == m - 1 && j == n - 1)
          dp[i][j] = -dungeon[i][j] + 1;
        else
          dp[i][j] =
              min(dp[i + 1][j] - dungeon[i][j], dp[i][j + 1] - dungeon[i][j]);
        dp[i][j] = max(dp[i][j], 1);
      }
    }
    return dp[0][0];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> dungeon = { { -2,-3,3 },{ -5,-10,1 },{ 10,30,-5 } };
  int ans = Solution().calculateMinimumHP(dungeon);
  assert(ans == 7);
  return 0;
}
