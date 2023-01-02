#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    memo_ = vector<vector<vector<int>>>(rows, vector<vector<int>>(cols, vector<int>(cols,-1)));
    return pickup(grid, 0, 0, cols-1);
  }

 private:
  int pickup(vector<vector<int>>& grid, int r, int c1, int c2) {
    int rows = grid.size(), cols = grid[0].size();
    if (r == rows) return 0;
    if (memo_[r][c1][c2] >= 0) return memo_[r][c1][c2];
    int ans = 0, cherry = grid[r][c1] + grid[r][c2];
    for (int j1 : {-1, 0, 1}) {
      int col1 = c1+j1;
      if (col1 < 0 || col1 >= cols) continue;
      for (int j2 : {-1, 0, 1}) {
        int col2 = c2+j2;
        if (col1 < 0 || col2 >= cols || col2 == col1) continue;
        ans = max(ans, pickup(grid, r+1, col1, col2));
      }
    }
    return memo_[r][c1][c2] = ans + cherry;
  }

  vector<vector<vector<int>>> memo_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> grid;
  int ans = 0;
  grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 24);

  grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 28);

  grid = {{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 22);

  grid = {{1,1},{1,1}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 4);

  grid = {{9,3,1,2},{9,9,2,2},{8,4,8,3},{9,2,7,7}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 54);

  grid = {{0,8,7,10,9,10,0,9,6},{8,7,10,8,7,4,9,6,10},{8,1,1,5,1,5,5,1,2},{9,4,10,8,8,1,9,5,0},{4,3,6,10,9,2,4,8,10},{7,3,2,8,3,3,5,9,8},{1,2,6,5,6,2,0,10,0}};
  ans = Solution().cherryPickup(grid);
  assert(ans == 96);
  return 0;
}
