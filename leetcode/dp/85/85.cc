#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();

    int ans = 0;
    vector<int> left(n), right(n, n), height(n);
    for (int i = 0; i < m; ++i) {
      int l = 0, r = n;
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) { left[j] = max(left[j], l); }
        else { left[j] = 0; l = j+1; }
      }
      for (int j = n-1; j >= 0; --j) {
        if (matrix[i][j]) { right[j] = min(right[j], r); }
        else { right[j] = n; r = j; }
      }
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) { height[j]++; }
        else { height[j] = 0; }
      }
      for (int j = 0; j < n; ++j) {
        int area = (right[j] - left[j]) * height[j];
        ans = max(ans, area);
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1},{1,0,0,1,0}};
  int ans = Solution().maximalRectangle(matrix);
  assert(ans == 6);

  matrix = {{1}};
  ans = Solution().maximalRectangle(matrix);
  assert(ans == 1);

  matrix = {{0}};
  ans = Solution().maximalRectangle(matrix);
  assert(ans == 0);

  return 0;
}
