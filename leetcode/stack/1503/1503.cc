#include <bits/stdc++.h>

using namespace std;

// Count Submatrices With All Ones
//
// this problem is actually pretty hard
// a more advance version of the histogram problem
//
// after compute the histogram, we need to define a dp(n)
// dp[j] mean the number of submatrices at j
// we also need to keep a stack such that
// every row[index] before current j is less than or equal to row[j]
// then it's easy to calculate dp[j]
// 1. if there are no index such that row[index] < row[j],
//  this means dp[j] is simply row[j] * (j+1)
// 2. if there are some index such that row[index] < row[j],
//  this means dp[j] = row[j] * (j-index) + dp[index]

class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int ans = 0;
    vector<int> row(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j])
          row[j]++;
        else
          row[j] = 0;
      }

      vector<int> sum(n);
      vector<int> index;
      for (int j = 0; j < n; ++j) {
        while (!index.empty() && row[index.back()] > row[j]) {
          index.pop_back();
        }

        if (index.empty()) {
          sum[j] += row[j] * (j + 1);
        } else {
          sum[j] = sum[index.back()];
          sum[j] += row[j] * (j - index.back());
        }
        index.push_back(j);
      }
      ans += accumulate(sum.begin(), sum.end(), 0);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
  int ans = Solution().numSubmat(mat);
  assert(ans == 13);

  mat = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
  ans = Solution().numSubmat(mat);
  assert(ans == 24);
  return 0;
}
