#include <bits/stdc++.h>

using namespace std;

// Cherry Pickup
//
// this one is super hard
//
// if we use greedy, this will not work because we need to also optimize the
// second trip back so the dp state should consider 2 coordinates at the same
// time (r1, c1) and (r2, c2)
//
// dp state should be the following
//
// dp[r1][c1][r2][c2] = max(dp[r1-1][c1][r2-1][c2],
//                          dp[r1-1][c1][r2][c2-1],
//                          dp[r1][c1-1][r2-1][c2],
//                          dp[r1][c1-1][r2-1][c2-1])
//
// luckly, we can compute r2 using r1, c1, c2, so the dp state only needs to be
// 3D
//
// so the dp state can be simplified as follow:
//
// dp[r1][c1][r2][c2] = max(dp[r1-1][c1][c2],
//                          dp[r1-1][c1][c2-1],
//                          dp[r1][c1-1][c2],
//                          dp[r1][c1-1][c2-1])
//
//
// Notes: there is a case where we cannot reach (n-1, n-1) from (0, 0),
// so we need to make dp initially -INF
// and dp[0][0][0] should be grid[0][0]

class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::min())));
    for (int r1 = 0; r1 < n; ++r1) {
      for (int c1 = 0; c1 < n; ++c1) {
        for (int c2 = 0; c2 < n; ++c2) {
          int r2 = r1 + c1 - c2;
          if (r2 < 0 || r2 >= n) continue;
          if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

          if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0) {
            dp[r1][c1][c2] = grid[r1][c1];
            continue;
          }

          int ans = dp[r1][c1][c2];
          int cherry = grid[r1][c1];
          if (r1 != r2 || c1 != c2) cherry += grid[r2][c2];

          if (c1 > 0) ans = max(ans, dp[r1][c1 - 1][c2]);
          if (r1 > 0) ans = max(ans, dp[r1 - 1][c1][c2]);
          if (c2 > 0 && c1 > 0) ans = max(ans, dp[r1][c1 - 1][c2 - 1]);
          if (c2 > 0 && r1 > 0) ans = max(ans, dp[r1 - 1][c1][c2 - 1]);
          dp[r1][c1][c2] = ans + cherry;
        }
      }
    }
    return max(dp[n - 1][n - 1][n - 1], 0);
  }
};

class Solution2 {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::min()));
    dp[0][0] = grid[0][0];

    for (int len = 1; len <= 2 * n - 2; ++len) {
      for (int c1 = n - 1; c1 >= 0; --c1) {
        for (int c2 = n - 1; c2 >= 0; --c2) {
          int r1 = len - c1, r2 = len - c2;
          if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n) {
            dp[c1][c2] = numeric_limits<int>::min();
            continue;
          }
          if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            dp[c1][c2] = numeric_limits<int>::min();
            continue;
          }

          int ans = dp[c1][c2];
          if (c1 > 0) ans = max(ans, dp[c1 - 1][c2]);
          if (c2 > 0) ans = max(ans, dp[c1][c2 - 1]);
          if (c1 > 0 && c2 > 0) ans = max(ans, dp[c1 - 1][c2 - 1]);

          int cherry = grid[r1][c1];
          if (r1 != r2 || c1 != c2) cherry += grid[r2][c2];
          dp[c1][c2] = ans + cherry;
        }
      }
    }
    return max(dp[n - 1][n - 1], 0);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> grid;
  int ans;

  grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 5);
  ans = Solution2().cherryPickup(grid);
  assert(ans == 5);

  grid = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 0);
  ans = Solution2().cherryPickup(grid);
  assert(ans == 0);

  grid = {{1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1},
          {1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 1, 1}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 15);
  ans = Solution2().cherryPickup(grid);
  assert(ans == 15);

  grid = {{1, 1, -1, 1, 1, 1, 0, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1, 0, 1},
          {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, -1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
          {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, -1, -1, -1, 1, 1, 1, -1, 1, -1, 1},
          {1, 1, 1, -1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, -1, -1, 1, 1, 1},
          {1, -1, -1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 0, 1, 1, 1, 1, 1, -1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
          {0, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
          {1, 1, -1, 1, 1, 1, -1, 1, 0, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1},
          {0, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1},
          {1, 1, -1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, -1, 0, 1, 0, -1, 1},
          {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, -1, 0},
          {1, 1, 1, 1, 1, 1, -1, 1, 0, 1, 1, 1, 1, -1, 1, 1, 1, 0, 1, 1},
          {1, 1, 1, 1, -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1},
          {-1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 0, 0, 1, 0, 1, 1},
          {0, 1, -1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 0, -1, 1, 1},
          {1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1},
          {1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 0, -1, 1, 1, 1, 1, 1, 1, 1, -1},
          {1, 1, 1, -1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, -1, 0, 1, 1},
          {1, 1, -1, 0, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, 0, 1},
          {-1, 0, 0, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 0, 1, 0, 0, 1, -1, 1}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 71);
  ans = Solution2().cherryPickup(grid);
  assert(ans == 71);
  return 0;
}
