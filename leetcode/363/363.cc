#include <bits/stdc++.h>

using namespace std;

// Max Sum of Rectangle No Larger Than K
// 
// doing this in 1D is easy with set
// 2D is tricky to implement
// 
// we need to let the row_sum be the sum from some starting column c1 to ending column c2
// and then proceed with the 1D solution

class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = numeric_limits<int>::min();
    for (int c = 0; c < n; ++c) {
      vector<int> row_sum(m);
      for (int j = c; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
          row_sum[i] += matrix[i][j];
          if (row_sum[i] <= k) ans = max(ans, row_sum[i]);
        }

        set<int> sums = {0};
        int sum = 0;
        for (int i = 0; i < m; ++i) {
          sum += row_sum[i];
          auto p = sums.lower_bound(sum - k);
          if (p != sums.end()) ans = max(ans, sum - *p);
          sums.insert(sum);
        }
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
  int k = 2;
  int ans = Solution().maxSumSubmatrix(matrix, k);
  assert(ans == 2);
  return 0;
}
