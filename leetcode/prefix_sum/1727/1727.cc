#include <bits/stdc++.h>

using namespace std;

// Largest Submatrix With Rearrangements
//
// naive idea is to compute a set for each row and union each row to get the max
// answer however this is O(m*n^2)
//
// the better idea is to sort the cumulative sum of columns
// we can sort the cumulative sum because we are allow to swap the columns any
// times we want this means when at cumulative_sum[i], it is guarantee that
// cumulative_sum[i+1] and other elements at the back is larger than
// cumulative_sum[i]

class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row_sum(n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0)
          row_sum[j] = 0;
        else
          row_sum[j]++;
      }

      vector<int> row = row_sum;
      sort(row.begin(), row.end());
      for (int j = 0; j < n; ++j) {
        ans = max(ans, row[j] * (n - j));
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  int ans = Solution().largestSubmatrix(matrix);
  assert(ans == 4);
  return 0;
}

