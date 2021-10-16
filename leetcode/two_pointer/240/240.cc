#include <bits/stdc++.h>

using namespace std;

// Search a 2D Matrix II
// 
// It's easy to come up with O(mlog(n))
// but we can do it faster
// the trick is to start at top right corner
// if current value is larger than target, go left
// if current value is smaller than target, go down
// if current value is target, there is the answer

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1;
    while (r < m && c >= 0) {
      if (matrix[r][c] == target) {
        return true;
      } else if (matrix[r][c] < target) {
        r++;
      } else {
        c--;
      }
    }
    return false;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  int target = 5;
  bool ans = Solution().searchMatrix(matrix, target);
  assert(ans);

  return 0;
}
