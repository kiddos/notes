#include <bits/stdc++.h>

using namespace std;

// Painting House II
//
// This problem can also be found in Binary search
// The naive DP

class Solution1 {
 public:
  int painHouse(vector<vector<int>>& matrix) {
    int n = matrix.size(), k = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(k, 1e9));
    dp[0] = vector<int>(k);
    for (int i = 1; i <= n; ++i) {
      for (int k1 = 0; k1 < k; ++k1) {
        for (int k2 = 0; k2 < k; ++k2)
          if (k1 != k2) {
            dp[i][k1] = min(dp[i][k1], dp[i - 1][k2] + matrix[i - 1][k2]);
          }
      }
    }
    int ans = numeric_limits<int>::max();
    for (int kk = 0; kk < k; ++kk) {
      ans = min(ans, dp[n][kk]);
    }
    return ans;
  }
};

// we actually just need to calculate the smallest and the second smallest DP
// for the next step

class Solution {
 public:
  int paintHouse(vector<vector<int>>& matrix) {
    int n = matrix.size(), k = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(k, 1e9));
    dp[0] = vector<int>(k);
    int first = 0, second = 0;
    for (int i = 1; i <= n; ++i) {
      int new_first = 1e9, new_second = 1e9;
      for (int kk = 0; kk < k; ++kk) {
        dp[i][kk] = min(dp[i][kk], (dp[i - 1][kk] == first ? second : first) +
                                       matrix[i - 1][kk]);
        new_second = min(new_second, dp[i][kk]);
        if (new_second < new_first) swap(new_first, new_second);
      }
      first = new_first;
      second = new_second;
    }
    /*
    for (int i = 0; i <= n; ++i) {
        for (int kk = 0; kk < k; ++kk) {
            cout << dp[i][kk] << " ";
        }
        cout << endl;
    }
    */
    return first;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = {
      {1, 5, 1}, {1, 5, 1}, {1, 5, 1}, {1, 5, 1}, {1, 5, 1}};

  int ans = Solution().paintHouse(matrix);
  assert(ans == 5);

  return 0;
}
